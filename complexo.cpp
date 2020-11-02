// Copyright 2018 Universidade Federal de Minas Gerais (UFMG)

#include "complexo.h"
#include <iostream>
#include <cmath>

void Complexo::calculaPolar(){
  r = modulo();
  if (imag_ == 0 && real_ == 0)
    teta = 0;
  else
    teta = atan2(imag_,real_);  
}
Complexo::Complexo() {
  real_ = 0.0;
  imag_ = 0.0;
  calculaPolar();
}

Complexo::Complexo(double a) {
  real_ = a;
  imag_ = 0.0;
calculaPolar();
}

Complexo::Complexo(double a, double b) {
  real_ = a;
  imag_ = b;
  calculaPolar();
}

double Complexo::real() const {
  return real_;
}

double Complexo::imag() const {
  return imag_;
}
double Complexo::raio() const {
    return r;
}
double Complexo::angulo() const {
    return teta;
}
void Complexo::setRaio(double Raio){
    r = Raio;
}
void Complexo::setAngulo(double Angulo){
    teta = Angulo;
}
bool Complexo::operator==(Complexo x) const {
  double aux;
  if (raio() > x.raio())
    aux = raio() - x.raio();
  else
    aux = x.raio() - raio();
  if (raio() != x.raio() && aux > 0.000001)
      return false;
  if (angulo() > x.angulo())
    aux = angulo() - x.angulo();
  else
    aux = x.angulo() - angulo();
   if (x.teta != teta && aux > 0.000001)
      return false;
  return true;
}

void Complexo::operator=(Complexo x) {
  real_ = x.real_;
  imag_ = x.imag_;
  r = x.r;
  teta = x.teta;
}

double Complexo::modulo() const {
  return sqrt(real_*real_ + imag_*imag_);
}

Complexo Complexo::conjugado() const {
  Complexo c(real_, -imag_);
  return c;
}

Complexo Complexo::operator-() const {
  if (imag_ != 0){
    Complexo c(-real_, -imag_);
    return c;
  }  
  else{
    Complexo c(-real_, 0);
    return c;  
  }
}
Complexo Complexo::inverso() const {
  Complexo a;
  a.setAngulo(-angulo());
  a.setRaio(1/raio());
  return a;
}

Complexo Complexo::operator+(Complexo y) const {
  Complexo s(real_ + y.real_, (imag_ + y.imag_));
  return s;
}

Complexo Complexo::operator-(Complexo y) const {
  return (*this) + -y;
}

Complexo Complexo::operator*(Complexo y) const {
  Complexo a;
  a.setRaio(raio() * y.raio());
  if (angulo() == 0.0 || y.angulo() == 0.0)
    a.setAngulo(0.0);
  else
    a.setAngulo((angulo() + y.angulo()));
  return a;
}

Complexo Complexo::operator/(Complexo y) const {
  
  if (angulo() >= 0.0)
    return (*this) * y.inverso();
  else{
      Complexo a = (*this) * y.inverso();
      double x = a.angulo();
      a.setAngulo(-x);
      return a;
  }
}
