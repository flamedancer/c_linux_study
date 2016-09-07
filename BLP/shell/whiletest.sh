#! /bin/bash



foo=1
while [ "${foo}" -le 20 ]; do
    echo "now the foo is" ${foo}
    foo=$((${foo} + 1))
done


echo "input you password"
read password

while [ ${password} != "123" ]; do
    echo "error  password!! inpurt again"
    read password
done

echo "Success! Congratulation!"
exit 0
