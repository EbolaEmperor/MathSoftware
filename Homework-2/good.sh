#!/bin/bash

lowbitret=0
qsumret=0

# lowbit函数，返回最低二进制位
lowbit(){
    lowbitret=$(($1&-$1))
}

# 使用 add p x 为数组p号位置的值增加x
add(){
    pos=$1
    val=$2
    while [ $pos -le $n ]
    do
        bitarr[$pos]=$((${bitarr[$pos]}+$val))
        lowbit $pos
        pos=$(($pos+$lowbitret))
    done
}

# 使用 qsum p x 查询[1,...,p]中所有数之和
qsum(){
    pos=$1
    res=0
    while [ $pos -gt 0 ]
    do
        res=$(($res+${bitarr[$pos]}))
        lowbit $pos
        pos=$(($pos-$lowbitret))
    done
    qsumret=$res
}

# 快速排序，同时记录排序后元素的原位置
qsort(){
    if [ $1 -lt $2 ]; then
        i=$1
        j=$2
        
        # 随机交换
        tmpid=$(($RANDOM%(j-i+1)+$i))
        tmpx=${arr[$i]}
        tmpy=${idx[$i]}
        arr[$i]=${arr[$tmpid]}
        idx[$i]=${idx[$tmpid]}
        arr[$tmpid]=$tmpx
        idx[$tmpid]=$tmpy
        
        k=${arr[$i]}
        tmpidx=${idx[$i]}
        while [ $i -lt $j ]; do
            while [ $i -lt $j ] && [ ${arr[$j]} -le $k ]; do
                j=$(($j-1))
            done
            if [ $i -lt $j ]; then
                idx[$i]=${idx[$j]}
                arr[$i]=${arr[$j]}
                i=$(($i+1))
            fi
            while [ $i -lt $j ] && [ ${arr[$i]} -gt $k ]; do
                i=$(($i+1))
            done
            if [ $i -lt $j ]; then
                idx[$j]=${idx[$i]}
                arr[$j]=${arr[$i]}
                j=$(($j-1))
            fi
        done
        arr[$i]=$k
        idx[$i]=$tmpidx
        qsort $1 $(($i-1))
        qsort $(($i+1)) $2
    fi
}

# 数组的总长
read -p "请输入数组的长度：" n
echo "请输入数组各元素（一行一个）"

# 初始化各数组
for ((i=1;i<=$n;i++)); do
    bitarr[$i]=0
    idx[$i]=$i
    read arr[$i]
done

# 排序后利用树状数组求逆序对数
qsort 1 $n
ans=0
for ((i=1;i<=$n;i++)); do
    add ${idx[$i]} 1
    qsum $((${idx[$i]}-1))
    ans=$(($ans+$qsumret))
done

# 输出逆序对数和排序后的数组
echo "逆序对数：" $ans
echo "从大到小排序后数组："
for ((i=1;i<=$n;i++)); do
    echo ${arr[$i]}
done