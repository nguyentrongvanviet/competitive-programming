echo off
git init
git remote add origin https://github.com/nguyentrongvanviet/competitive-programming.git
git add .
set /p comment=What do you want to comment ? 
git commit -m comment
git push -f origin main
echo on