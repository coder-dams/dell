# Projet Logiciel Transversal : dell
3rd Year Project

### Depedencies
Git
```bash
sudo apt install git
```
Dia 

```bash
sudo apt-get install dia
```
cmake and g++ 

```bash
sudo apt install cmake
sudo apt install g++
```
code coverage

```bash
sudo apt install lcov
sudo apt install gcovr
```
smfl
```bash
sudo apt-get install libsfml -dev
sudo apt-get install libboost-all-dev
```

## Build instructions

```bash
git clone https://github.com/coder-dams/dell
cd dell
mkdir build (first use only)
cd build
clean
cmake .. 
make -j
```


## Release History

* 2.2
    * Report 2.2
    * Engine diagram and implementation
    * Engine
```bash
./bin/client engine
```

* 2.1
    * Report 2.1
    * Render diagram
    * Implemented code to print a rendering of the map
    * Render 
```bash
./bin/client render
```

* 1.final
    * State diagram 
    * State implementation
    * Report 1.final
    * Unit test
```bash
make unittest
```

* 1.1
    * Implementing the code to print a message
    * Report 1.1
    * Hello World
```bash
./bin/client hello
```
