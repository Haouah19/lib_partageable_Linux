# lib_partageable_Linux
## Copies d’écran de la fenêtre de objdump :
  - Main :<br/><br/>
![alt text](https://github.com/Haouah19/lib_partageable_Linux/blob/main/pics/objdump-main.png)
  - Composant1 : <br/><br/>
![alt text](https://github.com/Haouah19/lib_partageable_Linux/blob/main/pics/objdump-libComposant1.png)

## Chargement dynamique des libs avec dlopen & dlsym :
  - Exécution : <br/>
`LD_LIBRARY_PATH=./lib ./lib/libComposant1.so ./lib/libComposant2.So` <br/>
`make`<br/>
  - Résultat : <br/><br/>
![alt text](https://github.com/Haouah19/lib_partageable_Linux/blob/main/pics/dlopen_dlsym.png)
