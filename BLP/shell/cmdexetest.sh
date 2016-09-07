#!/bin/sh

echo "The file name is :" $0
echo "The current eviroment is :" $PWD
echo "The current user is :" $(who)
set $(who)
echo "all arguments :" $*

exit 0
