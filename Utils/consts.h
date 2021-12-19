#ifndef _CONSTS_H
#define _CONSTS_H

// Address, Phone, Birthday = New types that will be used in Person type.

typedef struct {
  char street[50], comp[50], district[50], city[50], state[50], country[50];
  int zipCode, number;
} Address;

typedef struct {
	int ddd, number;
} Phone;

typedef struct {
	int day, month, year;
} Birthday;

// Type Person:
typedef struct {
  char firstName[50];
  char lastName[50];
  char email[50];
	int id;
	Birthday birthday;
	Address address;
	Phone phone;
} Person;

#endif