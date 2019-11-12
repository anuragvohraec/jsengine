# Jerryscript wrapper for easier usage of jerryscript
This is basically created to provide easier usage of jerryr script.
The original intention of this project is to integerate it with the flutter plugins, to provide a JSEngine.

## Prerequisite
Make sure cmake is installed on your system, on linux it will be : `sudo apt-get ninstall cmake`

## To build the project 
```
#assuming you in ./jerryscriptwrapper directory
cd build
#to create only the shared lib : libjerryscriptwrapper.so
cmake -DCREATEATESTAPP=OFF ../
#cmake ../  # will create assume CREATETESTAPP flag as OFF
#cmake -DCREATEATESTAPP=ON ../  # if you wnat to create a testapp file to test the build ass well.
```
