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
    'use '* )
        cmd_use_cd $cmd;;
    'show tracks' )
        cmd_show_tracks;;
    'add track' )
        cmd_add_track;;
    'del track' )
        cmd_del_track;;
    'help' )
        print_help;;
    'exit' )
        exit 0;;
    * )
        echo "  $cmd: command not found"
        print_help;;
    esac
}

print_help() {
    cat << !help!
     The commands are as follows:

     show cds
             List all of the eixts CDs

     add cds
             Add a new CD, you need to input some main msg, such as title

     del cd
             Select a CD catalog and then remove it

     up cd
             Select a CD, then you can update the information forrowing the instruction
     use *
             Select the current CD for future operation
     show tracks
             List all tracks of current CD 
     add track 
             Add a track to current CD
     del track
             Select and delete a track of current CD  
     exit 
             Exit the CD maintenance system
!help!
}


show_cds() {
    cat $title_file
}

cmd_show_cds() {
    show_cds
}


cmd_use_cd() {
    catalog=$2
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
        title=$2
    fi
    echo "Input the new CD type(just input RETURN to use the old one \"$3\" : \c"
    read type
    if [ -z "$type" ]; then
        type=$3
    fi
    echo "Input the new CD composer(just input RETURN to use the old \"$4\" : \c"
    read composer
    if [ -z "$composer" ]; then
        composer=$4
    fi
    del_cd
    add_cd
    echo 'update OK!'
}

add_cd() {
    echo $catalog,$title,$type,$composer >> $title_file
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
        cmd_add_cd
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


show_tracks() {
    echo "Catalog '$catalog'; Total $(grep -s ^${catalog}, $track_file | wc -l | xargs) "
    grep -s ^${catalog}, $track_file | cut -d ',' -f 2-
}

cmd_show_tracks() {
    show_tracks
}


add_track() {
    echo ${catalog},${track_no},${track_title} >> ${track_file}
}


cmd_add_track() {
    track_title=''
    echo 'Input the track title :\c'
    read track_title
    track_no=$(grep -s ^${catalog}, $track_file | cut -d ',' -f 2 | sort -nr | head -n 1)
    track_no=$((${track_no:-0} + 1))
    add_track
}

del_track() {
    grep -v ^${catalog},${track_no}, $track_file > $temp_file
    cat $temp_file | sort > $track_file
}

cmd_del_track() {
    track_no=''
    echo "Select the track num to delete:"
    show_tracks
    echo '    : \c'
    read track_no
    del_track 
    echo "del track '$track_no' OK!"

}



greeting
while :; do 
    get_cmd
done

exit 0
