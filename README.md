# strgen
A command line utility for generating a random string of characters, based on a set of rules
# Usage
### Generate a 32 character string using the default charset
```
 $ strgen -l 32
C!uRDzQPC1o541)efteqvyB$5#JGseMU
```
### Generate a random PIN
```
 $ strgen -l 4 -c 5
4149
```
### Generate a secure password applicable to most web sites
```
 $ strgen -l 24 -c 4 -e
MFUEiu4sieDKz#M^Gwx#ev2U
148.078200
```
### Generate a random number 0-9
```
 $ strgen -l 24 -c 4 -e
8
```
### Generate a list of 10 passwords and write them to a file
```
 $ echo (strgen -l 32 -r 10) > passwords.txt
 $ cat passwords.txt
^cgHoi0LbgLc9ISAhavOYw4RT*a$Ee1f 64N%&Lz*CV2iikI)kNN5%zoHu0tJc3OX P6vtmV0OfKWnEj9OWKmuTA2Xj#llOKT& k&mwyk%DUvAeEhC%RykpJWWSqSN#^*Yb %%y(3(lntvbHCoh@Mb(#XEC7b1H7VkYK 3bsx3DL$Ywd6KkTclBRS#)vQZ2szX*Uq (^OLe%xMkkCFv4Hqmd%!$&wvVOFhteya 1^L3KSfE@s%5dvd)jW11P4bajGhCuFD) gYNQwCa%U%WX8JG5l*xK!yKUOS$5$)R& X&t@wdB*XcDRwTorPL!fUb1(DwQ)v97(
```
# Compiling from source
Clone the repository
```
 $ git clone https://github.com/sdx6/strgen/
```
Ensure you have `clang` installed on your system, if not grab it from your local package manager
```
 $ sudo apt install clang
```
```
 $ sudo pacman -S clang
```
```
 $ sudo dnf install clang
```
```
 $ sudo zypper install clang
```
```
 $ apx install clang
```
```nix
environment.systemPackages = [
  pkgs.rocmPackages.llvm.clang
];
```
Move to the repository
```
 $ cd strgen/
```
Build and run
```
 $ make && ./strgen
```
Optionally, move the binary to /usr/bin/ so that it can be executed as a program
```
 $ sudo mv strgen /usr/bin/strgen
```
