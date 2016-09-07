#! /bin/bash


echo "Is moring now ?"

read check

case "${check}" in
    [Yy] | [Yy][Ee][Ss] )
        echo "you has input" ${check}
        echo "Good moring!"
        ;;
    [Nn]* )
        echo "you has input"  ${check}
        echo "Good afternoon!"
        ;;
    * )
        echo "Please give me a sure answer"
        exit 1
esac

exit 0
