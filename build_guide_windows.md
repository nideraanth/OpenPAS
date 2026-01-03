If you are just getting started and have Git for Windows installed:

    Clone the Repo:

```
git clone https://github.com/nideraanth/OpenPPS.git
cd OpenPPS
```
Clone the Experimental Branch (Optional): If you want the "deranged" features, use:
DOS
```
git checkout experimental
```
Build:

```
gcc main.c modules/src/*.c -o openpas.exe -Iinclude -Llib/windows -lraylib -lwinmm -lgdi32
```
For VMs:
```
gcc main.c modules/src/*.c -o openpas.exe -Iinclude -Llib/windows -lraylib -lwinmm -lgdi32 -lopengl32
```