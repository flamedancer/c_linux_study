#! /bin/sh

Version='1.0.1'

title_file="title.cdb"
track_file="track.cdb"
temp_file="/tmp/cdb.$$"
trap 'rm -f $temp_file' EXIT
cmd=''

greeting() {
    echo 'Welcome to my_CD_appliacton!'
    echo "Version $Version, Oct 8 2016, 12:17:30"
    echo 'Type "help" for more information'
}

get_cmd() {
    cmd=''
    echo '> \c'
    read cmd 
    do_cmd
}


do_cmd() {
    case "$cmd" in
    '' )
        return 0;;
    'show cds' )
        cmd_show_cds;;
    'add cd' )
        cmd_add_cd;;
    'del cd' )
        cmd_del_cd;;
    'up cd' )
        cmd_up_cd;;
    'exit' )
        exit 0;;
    * )
        echo "  $cmd: command not found";;
    esac
}

show_cds() {
    cat $title_file
}

cmd_show_cds() {
    show_cds
}

find_cd() {
    if [ -z "$(grep -s ^$catalog, $title_file)" ] || [ ! -e $title_file ]; then
        return 1
    fi
    return 0
}

del_cd() {
    grep -v ^${catalog}, $title_file > $temp_file
    cat $temp_file | sort > $title_file
}

cmd_del_cd() {
    catalog=''
    echo "Select the catelog to delete:"
    show_cds
    echo '    : \c'
    read catalog
    del_cd 
    echo "del $catalog OK!"
}


cmd_up_cd() {
    catalog=''
    echo "Select the catelog to update:"
    cmd_show_cds
    echo '    : \c'
    read catalog
    dump_IFS=$IFS
    echo $dump_IFS
    IFS=','
    set $(grep ^${catalog}, $title_file)
    IFS=$dump_IFS
    echo "Input the new CD title(just input RETURN to use the old one \"$2\" : \c"
    read title
    if [ -z "$title" ]; then
        title=$1
    fi
    echo "Input the new CD type(just input RETURN to use the old one \"$3\" : \c"
    read type
    if [ -z "$type" ]; then
        type=$2
    fi
    echo "Input the new CD composer(just input RETURN to use the old \"$4\" : \c"
    read composer
    if [ -z "$composer" ]; then
        composer=$3
    fi
    del_cd
    add_cd
    echo 'update OK!'
}

add_cd() {
    echo $catalog,$title,$type,$type,$composer >> $title_file
    cat $title_file | sort > $temp_file
    cat $temp_file > $title_file
}

cmd_add_cd() {
    catalog=''
    title=''
    type=''
    composer=''
    echo 'Input the CD catalog:\c'
    read catalog
    if find_cd; then 
        echo "Catalog is not unique, choise another!"
        return 1
    fi
    echo 'Input the CD title:\c'
    read title
    echo 'Input the CD type:\c'
    read type
    echo 'Input the CD composer:\c'
    read composer
    add_cd   
    echo 'Ok!'
}




greeting
while :; do 
    get_cmd
done

exit 0
