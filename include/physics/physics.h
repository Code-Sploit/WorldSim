#ifndef PHYSICS_H
#define PHYSICS_H

#define GRAVITY 9.8

int calculate_mass(int __force, int __gravity);
int calculate_force(int __mass, int __gravity);
int calculate_gravity(int __force, int __mass);

#endif