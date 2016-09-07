#!/bin/sh

echo "this day is" $(date)

set $(date)
echo "all params:" $0 $*
echo "so the month is" $2

exit 0
