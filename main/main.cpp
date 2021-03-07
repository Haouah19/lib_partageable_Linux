
#include <iostream>
#include <dlfcn.h>

int main(int argc, char ** argv)
{

	printf("Starting...");

	void *libComposant1;
	void *libComposant2;

	libComposant1 = dlopen ("libComposant1.so", RTLD_LAZY);
	if (!libComposant1) {
		printf ("Erreur dlopen: %s\n", dlerror());
        	exit(EXIT_FAILURE);
    	}

	libComposant2 = dlopen ("libComposant2.so", RTLD_LAZY);
	if (!libComposant2) {
		printf ("Erreur dlopen: %s\n", dlerror ());
		exit(EXIT_FAILURE);
    	}

	int (*composant1)(int, int) = (int (*)(int, int))dlsym(libComposant1, "_Z10composant1ii");
	if (!composant1) {
                printf ("Erreur dlsym: %s\n", dlerror());
                exit(EXIT_FAILURE);
        }
	int (*composant2)(int, int) = (int (*)(int, int))dlsym(libComposant2, "_Z10composant2ii");
	if (!composant2) {
                printf ("Erreur dlsym: %s\n", dlerror());
                exit(EXIT_FAILURE);
        }
	char *(*getComposant1Version)() = (char *(*)())dlsym(libComposant1, "_Z20getComposant1Versionv");
	if (!getComposant1Version) {
                printf ("Erreur dlsym: %s\n", dlerror());
                exit(EXIT_FAILURE);
        }

	int data1=3;
	int data2=5;
	int valeur1=composant1(data1,data2);
	int valeur2=composant2(data1,data2);

	std::cout << getComposant1Version() << std::endl;
	std::cout << "valeur 1 :" << valeur1 << " valeur 2 :" << valeur2 << std::endl;

	dlclose(libComposant1);
	dlclose(libComposant2);
}
