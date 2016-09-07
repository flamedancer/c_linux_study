#! /bin/bash 

echo  "is morning now?"

read check

if [ "${check}" = "yes" ]; then
    echo "good morning!"
elif [ "${check}" = "no" ]; then
    echo "good afternoon!"
else
    echo "please input yes or no "
fi

exit 0
