#include<stdio.h>
#include<stdlib.h>

char data[50], temp;
int key, countVariable;


//Retrieve the string from user
void getStringFromUser() {
	printf("Enter a String to be encoded/decoded:\t");
	scanf("%s", data);
}

//Retreive the key from user
void getKeyFromUser() {
	printf("What key to encode it with?:\t");
	scanf("%d", &key);
}

//Calling encryption
void encryption() {
	for (countVariable = 0; data[countVariable] != '\0'; countVariable++) {
		temp = data[countVariable];
		//Prevent going out of bounds
		if (temp >= 'a' && temp <= 'z') {
			temp = temp + key;
			if (temp > 'z') {
				temp = temp - 'z' + 'a' - 1;
			}
			data[countVariable] = temp;
		} else if (temp >= 'A' && temp <= 'Z') {
			temp = temp + key;
			if (temp > 'Z') {
				temp = temp - 'Z' + 'A' - 1;
			}
			data[countVariable] = temp;
		}
	}
	printf("\nEncrypted Message:\t%s\n", data);
}

//Calling decryption
void decryption() {
	for (countVariable = 0; data[countVariable] != '\0'; countVariable++) {
		temp = data[countVariable];
		if (temp >= 'a' && temp <= 'z') {
			temp = temp - key;
			if (temp < 'a') {
				temp = temp + 'z' - 'a' + 1;
			}
			data[countVariable] = temp;
		} else if (temp >= 'A' && temp <= 'Z') {
			temp = temp - key;
			if (temp < 'A') {
				temp = temp + 'Z' - 'A' + 1;
			}
			data[countVariable] = temp;
		}
	}
	printf("\nDecrypted Message:\t%s\n", data);
}

//Prompt for user
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
