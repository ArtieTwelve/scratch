//
// Created by smithla on 12/6/20.
//
#include <iostream>
#include <memory>
#ifndef SCRATCH_ENTITY_H
#define SCRATCH_ENTITY_H


class Entity {
    public:

         Entity();
         Entity(std::string);

         Entity(std::string,int i);
         // rule of five
         // 1 copy constructor
         Entity(const Entity&);
         // 2 copy assignment operator
         Entity& operator=(const Entity& ref);
         // 3 move constructor
         Entity(Entity&&);
         // 4 move assigment operator
         virtual Entity& operator=(Entity&& ref) noexcept;
         // 5 destructgr
         ~Entity();

         virtual void setInt(int i);
         virtual void setPi(int pi);
         virtual  void  setString(std::string s);
         virtual void setName(std::string n);
         virtual int getPi();


    private:
         std::string _name;
         int _i = 99;
         int* _preg = nullptr;
         std::unique_ptr<int> _pi{};
         std::string _s{"Default"};
};


class SimpleString {
public:
  SimpleString();
  SimpleString(int len, std::string str);

  // Rule of 5
  virtual ~SimpleString();
  SimpleString(const SimpleString& other);
  SimpleString& operator=(const SimpleString& other);
  SimpleString(SimpleString&& other);
  SimpleString& operator=(SimpleString&& other);


private:
    int _len;
    std::string _str;
};



#endif //SCRATCH_ENTITY_H
