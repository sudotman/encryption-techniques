#include<stdio.h>
#include<stdlib.h>

char data[50], temp;
int key, countVariable;

void getStringFromUser() {
	printf("Enter a String to be encoded/decoded:\t");
	scanf("%s", data);
}

void getKeyFromUser() {
	printf("What key to encode it with?:\t");
	scanf("%d", &key);
}

void encryption() {
	for (countVariable = 0; data[countVariable] != '\0'; countVariable++) {
		temp = data[countVariable];
		temp = temp + key;
		data[countVariable] = temp;
		
	}
	printf("\nEncrypted Message:\t%s\n", data);
}

void decryption() {
	for (countVariable = 0; data[countVariable] != '\0'; countVariable++) {
		
		temp = temp - key;
			
		data[countVariable] = temp;
		
	}
	printf("\nDecrypted Message:\t%s\n", data);
}

int main() {
	int modeSelected;
	printf("Welcome to Caesar-Cipher encryption/decryption demonstration.\n \n");
	getStringFromUser();
	getKeyFromUser();
	while (1) {
		printf("\n1. Encryption\n2. Decryption\n3. Enter new string/key\n4. Exit");
		printf("\nEnter You Choice:\t");
		scanf("%d", &modeSelected);
		switch (modeSelected) {
		case 1:
			encryption();
			break;
		case 2:
			decryption();
			break;
		case 3:
			main();
		case 4:
			exit(0);
		default:
			printf("\nPlease select a correct option:\n");
		}
	}
	printf("\n");
	return 0;
}
