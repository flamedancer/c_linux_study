#! /bin/bash

global_path="I am the global path"

foo(){
    local global_path="I am the local paht in a function"
    echo "the path in funtion: "
    echo ${global_path}
}

foo

echo "the path in global: "
echo ${global_path}


check_name(){
    echo "all_names: " $*
    for name in $*;do
        echo "this name is your?" ${name}
        read yes_or_no
        case ${yes_or_no} in
            [Yy][Ee][Ss] | [Yy] )
                echo "HELLO! ${name}"
                return 0
                ;;
            * )
                echo "sorry for disrecognise you  ${name}"
        esac
    done
    return 1
}

echo "input names:" $*
# shell 里  0 为true   1为false
if check_name $*;then
    echo "got you!!"
else
    echo "where are you?"
fi


f() {
    return 0 
}
if f
then
    echo ok 
fi
fr="$(f)"
echo $fr

f() {
    echo 0
}
if f
then
    echo ok 
fi
fr="$(f)"
echo $fr


f() {
    return "sdf" 
}
f

exit 0
