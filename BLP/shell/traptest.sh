#!/bin/sh

trap "rm -f /tmp/traptest_$$.txt" INT
date > /tmp/traptest_$$.txt

while [ -f "/tmp/traptest_$$.txt" ];do
    echo "the file is exist:" "/tmp/traptest_$$.txt"
    echo "please user CTRL-C to remove"
    sleep 1
done

echo "now the file is also exitsts?"
if [ -f /tmp/traptest_$$.txt ];then
    echo "yes"
else
    echo no
fi

trap "rm -f /tmp/traptest_*.txt;exit 0"  INT
date > /tmp/traptest_$$.txt
echo "the file has recreated"
while [ -f "/tmp/traptest_$$.txt" ];do
    echo "the file is exist:" "/tmp/traptest_$$.txt"
    echo "please user CTRL-C to remove"
    sleep 5
done

echo never get here

exit 0

