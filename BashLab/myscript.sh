#!/bin/bash
cd ~/Course_Resources
echo -n "Do you want to copy the file? 0 means No, 1 means Yes"
read int
echo $int
if [ $int == 1 ] 
then
    git pull
    cp -R live_code  ~/lab7_problem2
else
    echo "Thank you for using."
fi
