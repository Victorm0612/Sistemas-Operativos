# REGISTRO DE LO REALIZADO PARA EL SHELL

Para ejecutar el shell, es necesario tener en cuenta que al usarse la libreria readline, esta debe estar instalada en
su computador. Para instalarla simplemente escribir: 

```
sudo apt-get install libreadline-dev
```

Luego de esto, ya es posible compilarlo y ejecutarlo de la siguiente manera:

```
gcc shell.c -L/usr/include -lreadline -o shell && ./shell 
```

Agradecimientos especiales a la página geeksforgeeks.org por la información brindada que fue la base para el entendiemiento
del problema. 

