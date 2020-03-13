#include "Solver_ODE.h"

Solver_ODE::Solver_ODE(double t0, double x0, double dt, fPtr2v function)
{
	this->pFcn = function;
	this->t0 = t0;
	this->x0 = x0;
	this->dt = dt;
}

Solver_ODE::~Solver_ODE()
{
	;
}

double Solver_ODE::calculate(double t, double x)
{
	return this->pFcn(t,x);
}

double Solver_ODE::Euler_Explicit(double t)
{
	assert( t >= this->t0 );
	double range = (t - this->t0) / this->dt;
	double xt = this->x0;
	for (int i = 1; i <= range; i++) {
		xt += this->dt * this->calculate(t0 + i * this->dt, xt);
	}
	return xt;
}