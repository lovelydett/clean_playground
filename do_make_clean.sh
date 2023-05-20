# find all subdirectories with Makefile and run make clean

for f_name in `find . -name Makefile`; do
    dir_name=`dirname $f_name`
    make -C $dir_name clean
done