//
// Created by smithla on 12/6/20.
//
#include <iostream>
#ifndef SCRATCH_ENTITY_H
#define SCRATCH_ENTITY_H


class Entity {
    public:
         Entity();
         Entity(int i);
         Entity(Entity&);
         ~Entity();
         virtual Entity& operator=(Entity& ref);
         Entity(Entity&&);
         virtual Entity& operator=(Entity&& ref);
         virtual void setInt(int i);

    private:
         int _i;
};


#endif //SCRATCH_ENTITY_H
