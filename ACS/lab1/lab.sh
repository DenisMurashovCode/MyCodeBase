#!/bin/bash
echo -ne "Дата:\t\t\t"
date

echo -ne "Имя учётной записи:\t"
whoami

echo -ne "Доменное имя пк:\t"
hostname

echo "Процессор:"

echo -ne "\t* "
lscpu | grep "Имя модели:"
echo -ne "\t* "
lscpu | grep "Архитектура:"
echo -ne "\t*  "
cat /proc/cpuinfo | grep "cpu MHz"
echo -ne "\t*  "
lscpu | grep "CPU max MHz:"
echo -ne "\t* Количество ядер:\t\t   "
lscpu | grep -m1 "CPU(s):" | rev | cut -d' ' -f1 | rev
echo -ne "\t* Количество потоков\n\t  на одно ядро:\t\t\t   "
lscpu | grep -m1 "Thread(s) per core:" | rev | cut -d' ' -f1 | rev
echo -ne "\t* Загрузка процессора:\t\t   "
grep 'cpu ' /proc/stat | awk '{usage=($2+$4)*100/($2+$4+$5)} END {print usage "%"}'

echo "Оперативная память:"
echo -ne "\t* Всего:\t\t\t   "
free -h | grep "Память:" | tr -s ' ' | cut -d' ' -f2
echo -ne "\t* Доступно:\t\t\t   "
free -h | grep "Память:" | tr -s ' ' | cut -d' ' -f7
echo -ne "\t* Cache L1:\t\t\t   "
lscpu | grep "L1d cache"
echo -ne "\t* Cache L2:\t\t\t   "
lscpu | grep "L2 cache"
echo -ne "\t* Cache L3:\t\t\t   "
lscpu | grep "L3 cache"



echo "Жёсткий диск:"
echo -ne "\t* Всего:\t\t\t   "
df -h | grep "/dev/sda3" | tr -s ' ' | cut -d' ' -f2
echo -ne "\t* Доступно:\t\t\t   "
df -h | grep "/dev/sda3" | tr -s ' ' | cut -d' ' -f4
echo -ne "\t* Смонтировано в\n\t  корневую директорию:\t\t   "
df -h | grep "/$" | tr -s ' ' | cut -d' ' -f1
echo -ne "\t* Разделы:\t\t\t   "
df -h | tr -s ' ' | cut -d' ' -f '1,2,4'
echo -ne "\t* SWAP всего:\t\t\t   "
free -h | grep "Подкачка:" | tr -s ' ' | cut -d' ' -f2
echo -ne "\t* SWAP доступно:\t\t   "
free -h | grep "Подкачка:" | tr -s ' ' | cut -d' ' -f4

echo "Сетевые интерфейсы:"
echo -ne "\t* Количество сетевых\n\t  интерфейсов:\t\t\t   "
ls /sys/class/net/ | wc -l
echo -e "\nИмя сетевого интерфейса\t\tMAC адрес\t\tIP адрес\t\tСкорость соединения"
for var in /sys/class/net/*; do
  echo -ne "${var##*/}\t\t\t\t"
  tr "\n" "\t" < "$var/address"
  printf "%-24s" "$(ip -4 -o a | grep " ${var##*/} " | tr -s ' ' | cut -d' ' -f4 | tr -d '\n')"
  ip -4 -0 a | grep " ${var##*/}: " | tr -s ' ' | cut -d' ' -f13
done
