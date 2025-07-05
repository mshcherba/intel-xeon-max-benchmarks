#ifndef OPENSBLIBLOCK00_KERNEL_H
#define OPENSBLIBLOCK00_KERNEL_H
 void opensbliblock00Kernel087(ACC<float> &rhoE_B0, ACC<float> &rho_B0, ACC<float> &rhou0_B0, ACC<float> &rhou1_B0,
ACC<float> &rhou2_B0, const int *idx)
{
   float p = 0.0;
   float r = 0.0;
   float u0 = 0.0;
   float u1 = 0.0;
   float u2 = 0.0;
   float x0 = 0.0;
   float x1 = 0.0;
   float x2 = 0.0;
   x0 = Delta0block0*idx[0];

   x1 = Delta1block0*idx[1];

   x2 = Delta2block0*idx[2];

   u0 = cosf(x1)*cosf(x2)*sinf(x0);

   u1 = -cosf(x0)*cosf(x2)*sinf(x1);

   u2 = 0.0;

   p = (2.0 + cosf(2.0*x2))*(0.0625f*cosf(2.0*x0) + 0.0625f*cosf(2.0*x1)) + 1.0/((Minf*Minf)*gama);

   r = gama*p*(Minf*Minf);

   rho_B0(0,0,0) = r;

   rhou0_B0(0,0,0) = r*u0;

   rhou1_B0(0,0,0) = r*u1;

   rhou2_B0(0,0,0) = r*u2;

   rhoE_B0(0,0,0) = p/(-1 + gama) + 0.5f*r*((u0*u0) + (u1*u1) + (u2*u2));

}

 void opensbliblock00Kernel081(ACC<float> &rhoE_B0, ACC<float> &rho_B0, ACC<float> &rhou0_B0, ACC<float> &rhou1_B0,
ACC<float> &rhou2_B0)
{
   rho_B0(-1,0,0) = rho_B0(1,0,0);

   rhou0_B0(-1,0,0) = -half(1.0)*rhou0_B0(1,0,0);

   rhou1_B0(-1,0,0) = rhou1_B0(1,0,0);

   rhou2_B0(-1,0,0) = rhou2_B0(1,0,0);

   rhoE_B0(-1,0,0) = rhoE_B0(1,0,0);

   rho_B0(-2,0,0) = rho_B0(2,0,0);

   rhou0_B0(-2,0,0) = -half(1.0)*rhou0_B0(2,0,0);

   rhou1_B0(-2,0,0) = rhou1_B0(2,0,0);

   rhou2_B0(-2,0,0) = rhou2_B0(2,0,0);

   rhoE_B0(-2,0,0) = rhoE_B0(2,0,0);

}

 void opensbliblock00Kernel082(ACC<float> &rhoE_B0, ACC<float> &rho_B0, ACC<float> &rhou0_B0, ACC<float> &rhou1_B0,
ACC<float> &rhou2_B0)
{
   rho_B0(1,0,0) = rho_B0(-1,0,0);

   rhou0_B0(1,0,0) = -half(1.0)*rhou0_B0(-1,0,0);

   rhou1_B0(1,0,0) = rhou1_B0(-1,0,0);

   rhou2_B0(1,0,0) = rhou2_B0(-1,0,0);

   rhoE_B0(1,0,0) = rhoE_B0(-1,0,0);

   rho_B0(2,0,0) = rho_B0(-2,0,0);

   rhou0_B0(2,0,0) = -half(1.0)*rhou0_B0(-2,0,0);

   rhou1_B0(2,0,0) = rhou1_B0(-2,0,0);

   rhou2_B0(2,0,0) = rhou2_B0(-2,0,0);

   rhoE_B0(2,0,0) = rhoE_B0(-2,0,0);

}

 void opensbliblock00Kernel083(ACC<float> &rhoE_B0, ACC<float> &rho_B0, ACC<float> &rhou0_B0, ACC<float> &rhou1_B0,
ACC<float> &rhou2_B0)
{
   rho_B0(0,-1,0) = rho_B0(0,1,0);

   rhou0_B0(0,-1,0) = rhou0_B0(0,1,0);

   rhou1_B0(0,-1,0) = -half(1.0)*rhou1_B0(0,1,0);

   rhou2_B0(0,-1,0) = rhou2_B0(0,1,0);

   rhoE_B0(0,-1,0) = rhoE_B0(0,1,0);

   rho_B0(0,-2,0) = rho_B0(0,2,0);

   rhou0_B0(0,-2,0) = rhou0_B0(0,2,0);

   rhou1_B0(0,-2,0) = -half(1.0)*rhou1_B0(0,2,0);

   rhou2_B0(0,-2,0) = rhou2_B0(0,2,0);

   rhoE_B0(0,-2,0) = rhoE_B0(0,2,0);

}

 void opensbliblock00Kernel084(ACC<float> &rhoE_B0, ACC<float> &rho_B0, ACC<float> &rhou0_B0, ACC<float> &rhou1_B0,
ACC<float> &rhou2_B0)
{
   rho_B0(0,1,0) = rho_B0(0,-1,0);

   rhou0_B0(0,1,0) = rhou0_B0(0,-1,0);

   rhou1_B0(0,1,0) = -half(1.0)*rhou1_B0(0,-1,0);

   rhou2_B0(0,1,0) = rhou2_B0(0,-1,0);

   rhoE_B0(0,1,0) = rhoE_B0(0,-1,0);

   rho_B0(0,2,0) = rho_B0(0,-2,0);

   rhou0_B0(0,2,0) = rhou0_B0(0,-2,0);

   rhou1_B0(0,2,0) = -half(1.0)*rhou1_B0(0,-2,0);

   rhou2_B0(0,2,0) = rhou2_B0(0,-2,0);

   rhoE_B0(0,2,0) = rhoE_B0(0,-2,0);

}

 void opensbliblock00Kernel085(ACC<float> &rhoE_B0, ACC<float> &rho_B0, ACC<float> &rhou0_B0, ACC<float> &rhou1_B0,
ACC<float> &rhou2_B0)
{
   rho_B0(0,0,-1) = rho_B0(0,0,1);

   rhou0_B0(0,0,-1) = rhou0_B0(0,0,1);

   rhou1_B0(0,0,-1) = rhou1_B0(0,0,1);

   rhou2_B0(0,0,-1) = -half(1.0)*rhou2_B0(0,0,1);

   rhoE_B0(0,0,-1) = rhoE_B0(0,0,1);

   rho_B0(0,0,-2) = rho_B0(0,0,2);

   rhou0_B0(0,0,-2) = rhou0_B0(0,0,2);

   rhou1_B0(0,0,-2) = rhou1_B0(0,0,2);

   rhou2_B0(0,0,-2) = -half(1.0)*rhou2_B0(0,0,2);

   rhoE_B0(0,0,-2) = rhoE_B0(0,0,2);

}

 void opensbliblock00Kernel086(ACC<float> &rhoE_B0, ACC<float> &rho_B0, ACC<float> &rhou0_B0, ACC<float> &rhou1_B0,
ACC<float> &rhou2_B0)
{
   rho_B0(0,0,1) = rho_B0(0,0,-1);

   rhou0_B0(0,0,1) = rhou0_B0(0,0,-1);

   rhou1_B0(0,0,1) = rhou1_B0(0,0,-1);

   rhou2_B0(0,0,1) = -half(1.0)*rhou2_B0(0,0,-1);

   rhoE_B0(0,0,1) = rhoE_B0(0,0,-1);

   rho_B0(0,0,2) = rho_B0(0,0,-2);

   rhou0_B0(0,0,2) = rhou0_B0(0,0,-2);

   rhou1_B0(0,0,2) = rhou1_B0(0,0,-2);

   rhou2_B0(0,0,2) = -half(1.0)*rhou2_B0(0,0,-2);

   rhoE_B0(0,0,2) = rhoE_B0(0,0,-2);

}

 void opensbliblock00Kernel088(const ACC<float> &rhoE_B0, const ACC<float> &rho_B0, const ACC<float> &rhou0_B0, const
ACC<float> &rhou1_B0, const ACC<float> &rhou2_B0, ACC<float> &rhoE_RKold_B0, ACC<float> &rho_RKold_B0, ACC<float>
&rhou0_RKold_B0, ACC<float> &rhou1_RKold_B0, ACC<float> &rhou2_RKold_B0)
{
   rho_RKold_B0(0,0,0) = rho_B0(0,0,0);

   rhou0_RKold_B0(0,0,0) = rhou0_B0(0,0,0);

   rhou1_RKold_B0(0,0,0) = rhou1_B0(0,0,0);

   rhou2_RKold_B0(0,0,0) = rhou2_B0(0,0,0);

   rhoE_RKold_B0(0,0,0) = rhoE_B0(0,0,0);

}

void opensbliblock00Kernel002(const ACC<float> &rho_B0, const ACC<float> &rhou0_B0, ACC<float> &u0_B0)
{
   u0_B0(0,0,0) = rhou0_B0(0,0,0)/rho_B0(0,0,0);

}

void opensbliblock00Kernel024(const ACC<float> &rho_B0, const ACC<float> &rhou1_B0, ACC<float> &u1_B0)
{
   u1_B0(0,0,0) = rhou1_B0(0,0,0)/rho_B0(0,0,0);

}

void opensbliblock00Kernel037(const ACC<float> &rho_B0, const ACC<float> &rhou2_B0, ACC<float> &u2_B0)
{
   u2_B0(0,0,0) = rhou2_B0(0,0,0)/rho_B0(0,0,0);

}

 void opensbliblock00Kernel008(const ACC<float> &rhoE_B0, const ACC<float> &rho_B0, const ACC<float> &u0_B0, const
ACC<float> &u1_B0, const ACC<float> &u2_B0, ACC<float> &p_B0)
{
    p_B0(0,0,0) = (-1 + gama)*(-(half(1.0)/half(2.0))*(u0_B0(0,0,0)*u0_B0(0,0,0))*rho_B0(0,0,0) -
      (half(1.0)/half(2.0))*(u1_B0(0,0,0)*u1_B0(0,0,0))*rho_B0(0,0,0) - (half(1.0)/half(2.0))*(u2_B0(0,0,0)*u2_B0(0,0,0))*rho_B0(0,0,0) +
      rhoE_B0(0,0,0));

}

void opensbliblock00Kernel079(const ACC<float> &p_B0, const ACC<float> &rho_B0, ACC<float> &T_B0)
{
   T_B0(0,0,0) = (Minf*Minf)*gama*p_B0(0,0,0)/rho_B0(0,0,0);

}

 void opensbliblock00Kernel000(const ACC<float> &p_B0, const ACC<float> &rhoE_B0, const ACC<float> &rho_B0, const
ACC<float> &rhou0_B0, const ACC<float> &rhou1_B0, const ACC<float> &rhou2_B0, const ACC<float> &u0_B0, ACC<half>
&wk39_B0, ACC<half> &wk40_B0, ACC<half> &wk41_B0, ACC<half> &wk42_B0, ACC<half> &wk43_B0, ACC<half> &wk44_B0)
{
   wk39_B0(0,0,0) = u0_B0(0,0,0)*rhou1_B0(0,0,0);

   wk40_B0(0,0,0) = u0_B0(0,0,0)*rhou2_B0(0,0,0);

   wk41_B0(0,0,0) = u0_B0(0,0,0)*rhoE_B0(0,0,0);

   wk42_B0(0,0,0) = p_B0(0,0,0)*u0_B0(0,0,0);

   wk43_B0(0,0,0) = u0_B0(0,0,0)*rho_B0(0,0,0);

   wk44_B0(0,0,0) = u0_B0(0,0,0)*rhou0_B0(0,0,0);

}

void opensbliblock00Kernel003(const ACC<half> &wk39_B0, ACC<half> &wk0_B0)
{
    wk0_B0(0,0,0) = (-(half(2.0)/half(3.0))*wk39_B0(-1,0,0) - (half(1.0)/half(12.0))*wk39_B0(2,0,0) + ((half(1.0)/half(12.0)))*wk39_B0(-2,0,0) +
      ((half(2.0)/half(3.0)))*wk39_B0(1,0,0))*invDelta0block0;

}

void opensbliblock00Kernel005(const ACC<float> &rhou0_B0, ACC<half> &wk1_B0)
{
    wk1_B0(0,0,0) = (-(half(2.0)/half(3.0))*rhou0_B0(-1,0,0) - (half(1.0)/half(12.0))*rhou0_B0(2,0,0) + ((half(1.0)/half(12.0)))*rhou0_B0(-2,0,0) +
      ((half(2.0)/half(3.0)))*rhou0_B0(1,0,0))*invDelta0block0;

}

void opensbliblock00Kernel007(const ACC<half> &wk40_B0, ACC<half> &wk2_B0)
{
    wk2_B0(0,0,0) = (-(half(2.0)/half(3.0))*wk40_B0(-1,0,0) - (half(1.0)/half(12.0))*wk40_B0(2,0,0) + ((half(1.0)/half(12.0)))*wk40_B0(-2,0,0) +
      ((half(2.0)/half(3.0)))*wk40_B0(1,0,0))*invDelta0block0;

}

void opensbliblock00Kernel009(const ACC<float> &p_B0, ACC<half> &wk3_B0)
{
    wk3_B0(0,0,0) = (-(half(2.0)/half(3.0))*p_B0(-1,0,0) - (half(1.0)/half(12.0))*p_B0(2,0,0) + ((half(1.0)/half(12.0)))*p_B0(-2,0,0) +
      ((half(2.0)/half(3.0)))*p_B0(1,0,0))*invDelta0block0;

}

void opensbliblock00Kernel011(const ACC<half> &wk41_B0, ACC<half> &wk4_B0)
{
    wk4_B0(0,0,0) = (-(half(2.0)/half(3.0))*wk41_B0(-1,0,0) - (half(1.0)/half(12.0))*wk41_B0(2,0,0) + ((half(1.0)/half(12.0)))*wk41_B0(-2,0,0) +
      ((half(2.0)/half(3.0)))*wk41_B0(1,0,0))*invDelta0block0;

}

void opensbliblock00Kernel012(const ACC<float> &rhoE_B0, ACC<half> &wk5_B0)
{
    wk5_B0(0,0,0) = (-(half(2.0)/half(3.0))*rhoE_B0(-1,0,0) - (half(1.0)/half(12.0))*rhoE_B0(2,0,0) + ((half(1.0)/half(12.0)))*rhoE_B0(-2,0,0) +
      ((half(2.0)/half(3.0)))*rhoE_B0(1,0,0))*invDelta0block0;

}

void opensbliblock00Kernel013(const ACC<float> &rhou1_B0, ACC<half> &wk6_B0)
{
    wk6_B0(0,0,0) = (-(half(2.0)/half(3.0))*rhou1_B0(-1,0,0) - (half(1.0)/half(12.0))*rhou1_B0(2,0,0) + ((half(1.0)/half(12.0)))*rhou1_B0(-2,0,0) +
      ((half(2.0)/half(3.0)))*rhou1_B0(1,0,0))*invDelta0block0;

}

void opensbliblock00Kernel014(const ACC<half> &wk42_B0, ACC<half> &wk7_B0)
{
    wk7_B0(0,0,0) = (-(half(2.0)/half(3.0))*wk42_B0(-1,0,0) - (half(1.0)/half(12.0))*wk42_B0(2,0,0) + ((half(1.0)/half(12.0)))*wk42_B0(-2,0,0) +
      ((half(2.0)/half(3.0)))*wk42_B0(1,0,0))*invDelta0block0;

}

void opensbliblock00Kernel016(const ACC<half> &wk43_B0, ACC<half> &wk8_B0)
{
    wk8_B0(0,0,0) = (-(half(2.0)/half(3.0))*wk43_B0(-1,0,0) - (half(1.0)/half(12.0))*wk43_B0(2,0,0) + ((half(1.0)/half(12.0)))*wk43_B0(-2,0,0) +
      ((half(2.0)/half(3.0)))*wk43_B0(1,0,0))*invDelta0block0;

}

void opensbliblock00Kernel017(const ACC<float> &u0_B0, ACC<half> &wk9_B0)
{
    wk9_B0(0,0,0) = (-(half(2.0)/half(3.0))*u0_B0(-1,0,0) - (half(1.0)/half(12.0))*u0_B0(2,0,0) + ((half(1.0)/half(12.0)))*u0_B0(-2,0,0) +
      ((half(2.0)/half(3.0)))*u0_B0(1,0,0))*invDelta0block0;

}

void opensbliblock00Kernel018(const ACC<float> &rhou2_B0, ACC<half> &wk10_B0)
{
    wk10_B0(0,0,0) = (-(half(2.0)/half(3.0))*rhou2_B0(-1,0,0) - (half(1.0)/half(12.0))*rhou2_B0(2,0,0) + ((half(1.0)/half(12.0)))*rhou2_B0(-2,0,0) +
      ((half(2.0)/half(3.0)))*rhou2_B0(1,0,0))*invDelta0block0;

}

void opensbliblock00Kernel019(const ACC<half> &wk44_B0, ACC<half> &wk11_B0)
{
    wk11_B0(0,0,0) = (-(half(2.0)/half(3.0))*wk44_B0(-1,0,0) - (half(1.0)/half(12.0))*wk44_B0(2,0,0) + ((half(1.0)/half(12.0)))*wk44_B0(-2,0,0) +
      ((half(2.0)/half(3.0)))*wk44_B0(1,0,0))*invDelta0block0;

}

void opensbliblock00Kernel020(const ACC<float> &rho_B0, ACC<half> &wk12_B0)
{
    wk12_B0(0,0,0) = (-(half(2.0)/half(3.0))*rho_B0(-1,0,0) - (half(1.0)/half(12.0))*rho_B0(2,0,0) + ((half(1.0)/half(12.0)))*rho_B0(-2,0,0) +
      ((half(2.0)/half(3.0)))*rho_B0(1,0,0))*invDelta0block0;

}

 void opensbliblock00Kernel021(const ACC<float> &p_B0, const ACC<float> &rhoE_B0, const ACC<float> &rho_B0, const
ACC<float> &rhou0_B0, const ACC<float> &rhou1_B0, const ACC<float> &rhou2_B0, const ACC<float> &u1_B0, ACC<half>
&wk39_B0, ACC<half> &wk40_B0, ACC<half> &wk41_B0, ACC<half> &wk42_B0, ACC<half> &wk43_B0, ACC<half> &wk44_B0)
{
   wk39_B0(0,0,0) = u1_B0(0,0,0)*rhou1_B0(0,0,0);

   wk40_B0(0,0,0) = u1_B0(0,0,0)*rho_B0(0,0,0);

   wk41_B0(0,0,0) = u1_B0(0,0,0)*rhou0_B0(0,0,0);

   wk42_B0(0,0,0) = p_B0(0,0,0)*u1_B0(0,0,0);

   wk43_B0(0,0,0) = u1_B0(0,0,0)*rhoE_B0(0,0,0);

   wk44_B0(0,0,0) = u1_B0(0,0,0)*rhou2_B0(0,0,0);

}

void opensbliblock00Kernel022(const ACC<float> &rhou1_B0, ACC<half> &wk13_B0)
{
    wk13_B0(0,0,0) = (-(half(2.0)/half(3.0))*rhou1_B0(0,-1,0) - (half(1.0)/half(12.0))*rhou1_B0(0,2,0) + ((half(1.0)/half(12.0)))*rhou1_B0(0,-2,0) +
      ((half(2.0)/half(3.0)))*rhou1_B0(0,1,0))*invDelta1block0;

}

void opensbliblock00Kernel023(const ACC<float> &rho_B0, ACC<half> &wk14_B0)
{
    wk14_B0(0,0,0) = (-(half(2.0)/half(3.0))*rho_B0(0,-1,0) - (half(1.0)/half(12.0))*rho_B0(0,2,0) + ((half(1.0)/half(12.0)))*rho_B0(0,-2,0) +
      ((half(2.0)/half(3.0)))*rho_B0(0,1,0))*invDelta1block0;

}

void opensbliblock00Kernel025(const ACC<half> &wk39_B0, ACC<half> &wk15_B0)
{
    wk15_B0(0,0,0) = (-(half(2.0)/half(3.0))*wk39_B0(0,-1,0) - (half(1.0)/half(12.0))*wk39_B0(0,2,0) + ((half(1.0)/half(12.0)))*wk39_B0(0,-2,0) +
      ((half(2.0)/half(3.0)))*wk39_B0(0,1,0))*invDelta1block0;

}

void opensbliblock00Kernel026(const ACC<half> &wk40_B0, ACC<half> &wk16_B0)
{
    wk16_B0(0,0,0) = (-(half(2.0)/half(3.0))*wk40_B0(0,-1,0) - (half(1.0)/half(12.0))*wk40_B0(0,2,0) + ((half(1.0)/half(12.0)))*wk40_B0(0,-2,0) +
      ((half(2.0)/half(3.0)))*wk40_B0(0,1,0))*invDelta1block0;

}

void opensbliblock00Kernel027(const ACC<float> &rhou2_B0, ACC<half> &wk17_B0)
{
    wk17_B0(0,0,0) = (-(half(2.0)/half(3.0))*rhou2_B0(0,-1,0) - (half(1.0)/half(12.0))*rhou2_B0(0,2,0) + ((half(1.0)/half(12.0)))*rhou2_B0(0,-2,0) +
      ((half(2.0)/half(3.0)))*rhou2_B0(0,1,0))*invDelta1block0;

}

void opensbliblock00Kernel028(const ACC<float> &p_B0, ACC<half> &wk18_B0)
{
    wk18_B0(0,0,0) = (-(half(2.0)/half(3.0))*p_B0(0,-1,0) - (half(1.0)/half(12.0))*p_B0(0,2,0) + ((half(1.0)/half(12.0)))*p_B0(0,-2,0) +
      ((half(2.0)/half(3.0)))*p_B0(0,1,0))*invDelta1block0;

}

void opensbliblock00Kernel029(const ACC<half> &wk41_B0, ACC<half> &wk19_B0)
{
    wk19_B0(0,0,0) = (-(half(2.0)/half(3.0))*wk41_B0(0,-1,0) - (half(1.0)/half(12.0))*wk41_B0(0,2,0) + ((half(1.0)/half(12.0)))*wk41_B0(0,-2,0) +
      ((half(2.0)/half(3.0)))*wk41_B0(0,1,0))*invDelta1block0;

}

void opensbliblock00Kernel030(const ACC<float> &rhoE_B0, ACC<half> &wk20_B0)
{
    wk20_B0(0,0,0) = (-(half(2.0)/half(3.0))*rhoE_B0(0,-1,0) - (half(1.0)/half(12.0))*rhoE_B0(0,2,0) + ((half(1.0)/half(12.0)))*rhoE_B0(0,-2,0) +
      ((half(2.0)/half(3.0)))*rhoE_B0(0,1,0))*invDelta1block0;

}

void opensbliblock00Kernel031(const ACC<float> &rhou0_B0, ACC<half> &wk21_B0)
{
    wk21_B0(0,0,0) = (-(half(2.0)/half(3.0))*rhou0_B0(0,-1,0) - (half(1.0)/half(12.0))*rhou0_B0(0,2,0) + ((half(1.0)/half(12.0)))*rhou0_B0(0,-2,0) +
      ((half(2.0)/half(3.0)))*rhou0_B0(0,1,0))*invDelta1block0;

}

void opensbliblock00Kernel032(const ACC<half> &wk42_B0, ACC<half> &wk22_B0)
{
    wk22_B0(0,0,0) = (-(half(2.0)/half(3.0))*wk42_B0(0,-1,0) - (half(1.0)/half(12.0))*wk42_B0(0,2,0) + ((half(1.0)/half(12.0)))*wk42_B0(0,-2,0) +
      ((half(2.0)/half(3.0)))*wk42_B0(0,1,0))*invDelta1block0;

}

void opensbliblock00Kernel033(const ACC<float> &u1_B0, ACC<half> &wk23_B0)
{
    wk23_B0(0,0,0) = (-(half(2.0)/half(3.0))*u1_B0(0,-1,0) - (half(1.0)/half(12.0))*u1_B0(0,2,0) + ((half(1.0)/half(12.0)))*u1_B0(0,-2,0) +
      ((half(2.0)/half(3.0)))*u1_B0(0,1,0))*invDelta1block0;

}

void opensbliblock00Kernel034(const ACC<half> &wk43_B0, ACC<half> &wk24_B0)
{
    wk24_B0(0,0,0) = (-(half(2.0)/half(3.0))*wk43_B0(0,-1,0) - (half(1.0)/half(12.0))*wk43_B0(0,2,0) + ((half(1.0)/half(12.0)))*wk43_B0(0,-2,0) +
      ((half(2.0)/half(3.0)))*wk43_B0(0,1,0))*invDelta1block0;

}

void opensbliblock00Kernel035(const ACC<half> &wk44_B0, ACC<half> &wk25_B0)
{
    wk25_B0(0,0,0) = (-(half(2.0)/half(3.0))*wk44_B0(0,-1,0) - (half(1.0)/half(12.0))*wk44_B0(0,2,0) + ((half(1.0)/half(12.0)))*wk44_B0(0,-2,0) +
      ((half(2.0)/half(3.0)))*wk44_B0(0,1,0))*invDelta1block0;

}

 void opensbliblock00Kernel036(const ACC<float> &p_B0, const ACC<float> &rhoE_B0, const ACC<float> &rho_B0, const
ACC<float> &rhou0_B0, const ACC<float> &rhou1_B0, const ACC<float> &rhou2_B0, const ACC<float> &u2_B0, ACC<half>
&wk39_B0, ACC<half> &wk40_B0, ACC<half> &wk41_B0, ACC<half> &wk42_B0, ACC<half> &wk43_B0, ACC<half> &wk44_B0)
{
   wk39_B0(0,0,0) = u2_B0(0,0,0)*rhou2_B0(0,0,0);

   wk40_B0(0,0,0) = u2_B0(0,0,0)*rhoE_B0(0,0,0);

   wk41_B0(0,0,0) = u2_B0(0,0,0)*rho_B0(0,0,0);

   wk42_B0(0,0,0) = u2_B0(0,0,0)*rhou0_B0(0,0,0);

   wk43_B0(0,0,0) = p_B0(0,0,0)*u2_B0(0,0,0);

   wk44_B0(0,0,0) = u2_B0(0,0,0)*rhou1_B0(0,0,0);

}

void opensbliblock00Kernel038(const ACC<half> &wk39_B0, ACC<half> &wk26_B0)
{
    wk26_B0(0,0,0) = (-(half(2.0)/half(3.0))*wk39_B0(0,0,-1) - (half(1.0)/half(12.0))*wk39_B0(0,0,2) + ((half(1.0)/half(12.0)))*wk39_B0(0,0,-2) +
      ((half(2.0)/half(3.0)))*wk39_B0(0,0,1))*invDelta2block0;

}

void opensbliblock00Kernel039(const ACC<float> &rhoE_B0, ACC<half> &wk27_B0)
{
    wk27_B0(0,0,0) = (-(half(2.0)/half(3.0))*rhoE_B0(0,0,-1) - (half(1.0)/half(12.0))*rhoE_B0(0,0,2) + ((half(1.0)/half(12.0)))*rhoE_B0(0,0,-2) +
      ((half(2.0)/half(3.0)))*rhoE_B0(0,0,1))*invDelta2block0;

}

void opensbliblock00Kernel040(const ACC<half> &wk40_B0, ACC<half> &wk28_B0)
{
    wk28_B0(0,0,0) = (-(half(2.0)/half(3.0))*wk40_B0(0,0,-1) - (half(1.0)/half(12.0))*wk40_B0(0,0,2) + ((half(1.0)/half(12.0)))*wk40_B0(0,0,-2) +
      ((half(2.0)/half(3.0)))*wk40_B0(0,0,1))*invDelta2block0;

}

void opensbliblock00Kernel041(const ACC<float> &rhou0_B0, ACC<half> &wk29_B0)
{
    wk29_B0(0,0,0) = (-(half(2.0)/half(3.0))*rhou0_B0(0,0,-1) - (half(1.0)/half(12.0))*rhou0_B0(0,0,2) + ((half(1.0)/half(12.0)))*rhou0_B0(0,0,-2) +
      ((half(2.0)/half(3.0)))*rhou0_B0(0,0,1))*invDelta2block0;

}

void opensbliblock00Kernel042(const ACC<half> &wk41_B0, ACC<half> &wk30_B0)
{
    wk30_B0(0,0,0) = (-(half(2.0)/half(3.0))*wk41_B0(0,0,-1) - (half(1.0)/half(12.0))*wk41_B0(0,0,2) + ((half(1.0)/half(12.0)))*wk41_B0(0,0,-2) +
      ((half(2.0)/half(3.0)))*wk41_B0(0,0,1))*invDelta2block0;

}

void opensbliblock00Kernel043(const ACC<half> &wk42_B0, ACC<half> &wk31_B0)
{
    wk31_B0(0,0,0) = (-(half(2.0)/half(3.0))*wk42_B0(0,0,-1) - (half(1.0)/half(12.0))*wk42_B0(0,0,2) + ((half(1.0)/half(12.0)))*wk42_B0(0,0,-2) +
      ((half(2.0)/half(3.0)))*wk42_B0(0,0,1))*invDelta2block0;

}

void opensbliblock00Kernel044(const ACC<float> &rhou1_B0, ACC<half> &wk32_B0)
{
    wk32_B0(0,0,0) = (-(half(2.0)/half(3.0))*rhou1_B0(0,0,-1) - (half(1.0)/half(12.0))*rhou1_B0(0,0,2) + ((half(1.0)/half(12.0)))*rhou1_B0(0,0,-2) +
      ((half(2.0)/half(3.0)))*rhou1_B0(0,0,1))*invDelta2block0;

}

void opensbliblock00Kernel045(const ACC<float> &p_B0, ACC<half> &wk33_B0)
{
    wk33_B0(0,0,0) = (-(half(2.0)/half(3.0))*p_B0(0,0,-1) - (half(1.0)/half(12.0))*p_B0(0,0,2) + ((half(1.0)/half(12.0)))*p_B0(0,0,-2) +
      ((half(2.0)/half(3.0)))*p_B0(0,0,1))*invDelta2block0;

}

void opensbliblock00Kernel046(const ACC<float> &rhou2_B0, ACC<half> &wk34_B0)
{
    wk34_B0(0,0,0) = (-(half(2.0)/half(3.0))*rhou2_B0(0,0,-1) - (half(1.0)/half(12.0))*rhou2_B0(0,0,2) + ((half(1.0)/half(12.0)))*rhou2_B0(0,0,-2) +
      ((half(2.0)/half(3.0)))*rhou2_B0(0,0,1))*invDelta2block0;

}

void opensbliblock00Kernel047(const ACC<half> &wk43_B0, ACC<half> &wk35_B0)
{
    wk35_B0(0,0,0) = (-(half(2.0)/half(3.0))*wk43_B0(0,0,-1) - (half(1.0)/half(12.0))*wk43_B0(0,0,2) + ((half(1.0)/half(12.0)))*wk43_B0(0,0,-2) +
      ((half(2.0)/half(3.0)))*wk43_B0(0,0,1))*invDelta2block0;

}

void opensbliblock00Kernel048(const ACC<half> &wk44_B0, ACC<half> &wk36_B0)
{
    wk36_B0(0,0,0) = (-(half(2.0)/half(3.0))*wk44_B0(0,0,-1) - (half(1.0)/half(12.0))*wk44_B0(0,0,2) + ((half(1.0)/half(12.0)))*wk44_B0(0,0,-2) +
      ((half(2.0)/half(3.0)))*wk44_B0(0,0,1))*invDelta2block0;

}

void opensbliblock00Kernel049(const ACC<float> &rho_B0, ACC<half> &wk37_B0)
{
    wk37_B0(0,0,0) = (-(half(2.0)/half(3.0))*rho_B0(0,0,-1) - (half(1.0)/half(12.0))*rho_B0(0,0,2) + ((half(1.0)/half(12.0)))*rho_B0(0,0,-2) +
      ((half(2.0)/half(3.0)))*rho_B0(0,0,1))*invDelta2block0;

}

void opensbliblock00Kernel050(const ACC<float> &u2_B0, ACC<half> &wk38_B0)
{
    wk38_B0(0,0,0) = (-(half(2.0)/half(3.0))*u2_B0(0,0,-1) - (half(1.0)/half(12.0))*u2_B0(0,0,2) + ((half(1.0)/half(12.0)))*u2_B0(0,0,-2) +
      ((half(2.0)/half(3.0)))*u2_B0(0,0,1))*invDelta2block0;

}

 void opensbliblock00Kernel051(const ACC<float> &rhoE_B0, const ACC<float> &rho_B0, const ACC<float> &rhou0_B0, const
ACC<float> &rhou1_B0, const ACC<float> &rhou2_B0, const ACC<float> &u0_B0, const ACC<float> &u1_B0, const ACC<float>
&u2_B0, const ACC<half> &wk0_B0, const ACC<half> &wk10_B0, const ACC<half> &wk11_B0, const ACC<half> &wk12_B0, const
ACC<half> &wk13_B0, const ACC<half> &wk14_B0, const ACC<half> &wk15_B0, const ACC<half> &wk16_B0, const ACC<half>
&wk17_B0, const ACC<half> &wk18_B0, const ACC<half> &wk19_B0, const ACC<half> &wk1_B0, const ACC<half> &wk20_B0, const
ACC<half> &wk21_B0, const ACC<half> &wk22_B0, const ACC<half> &wk23_B0, const ACC<half> &wk24_B0, const ACC<half>
&wk25_B0, const ACC<half> &wk26_B0, const ACC<half> &wk27_B0, const ACC<half> &wk28_B0, const ACC<half> &wk29_B0, const
ACC<half> &wk2_B0, const ACC<half> &wk30_B0, const ACC<half> &wk31_B0, const ACC<half> &wk32_B0, const ACC<half>
&wk33_B0, const ACC<half> &wk34_B0, const ACC<half> &wk35_B0, const ACC<half> &wk36_B0, const ACC<half> &wk37_B0, const
ACC<half> &wk38_B0, const ACC<half> &wk3_B0, const ACC<half> &wk4_B0, const ACC<half> &wk5_B0, const ACC<half> &wk6_B0,
const ACC<half> &wk7_B0, const ACC<half> &wk8_B0, const ACC<half> &wk9_B0, ACC<float> &Residual0_B0, ACC<float>
&Residual1_B0, ACC<float> &Residual2_B0, ACC<float> &Residual3_B0, ACC<float> &Residual4_B0)
{
    Residual0_B0(0,0,0) = -(half(1.0)/half(2.0))*wk8_B0(0,0,0) - (half(1.0)/half(2.0))*wk16_B0(0,0,0) - (half(1.0)/half(2.0))*wk30_B0(0,0,0) -
      (half(1.0)/half(2.0))*(wk9_B0(0,0,0) + wk23_B0(0,0,0) + wk38_B0(0,0,0))*rho_B0(0,0,0) -
      (half(1.0)/half(2.0))*u0_B0(0,0,0)*wk12_B0(0,0,0) - (half(1.0)/half(2.0))*u1_B0(0,0,0)*wk14_B0(0,0,0) -
      (half(1.0)/half(2.0))*u2_B0(0,0,0)*wk37_B0(0,0,0);

    Residual1_B0(0,0,0) = -wk3_B0(0,0,0) - (half(1.0)/half(2.0))*wk11_B0(0,0,0) - (half(1.0)/half(2.0))*wk19_B0(0,0,0) -
      (half(1.0)/half(2.0))*wk31_B0(0,0,0) - (half(1.0)/half(2.0))*(wk9_B0(0,0,0) + wk23_B0(0,0,0) + wk38_B0(0,0,0))*rhou0_B0(0,0,0) -
      (half(1.0)/half(2.0))*u0_B0(0,0,0)*wk1_B0(0,0,0) - (half(1.0)/half(2.0))*u1_B0(0,0,0)*wk21_B0(0,0,0) -
      (half(1.0)/half(2.0))*u2_B0(0,0,0)*wk29_B0(0,0,0);

    Residual2_B0(0,0,0) = -wk18_B0(0,0,0) - (half(1.0)/half(2.0))*wk0_B0(0,0,0) - (half(1.0)/half(2.0))*wk15_B0(0,0,0) -
      (half(1.0)/half(2.0))*wk36_B0(0,0,0) - (half(1.0)/half(2.0))*(wk9_B0(0,0,0) + wk23_B0(0,0,0) + wk38_B0(0,0,0))*rhou1_B0(0,0,0) -
      (half(1.0)/half(2.0))*u0_B0(0,0,0)*wk6_B0(0,0,0) - (half(1.0)/half(2.0))*u1_B0(0,0,0)*wk13_B0(0,0,0) -
      (half(1.0)/half(2.0))*u2_B0(0,0,0)*wk32_B0(0,0,0);

    Residual3_B0(0,0,0) = -wk33_B0(0,0,0) - (half(1.0)/half(2.0))*wk2_B0(0,0,0) - (half(1.0)/half(2.0))*wk25_B0(0,0,0) -
      (half(1.0)/half(2.0))*wk26_B0(0,0,0) - (half(1.0)/half(2.0))*(wk9_B0(0,0,0) + wk23_B0(0,0,0) + wk38_B0(0,0,0))*rhou2_B0(0,0,0) -
      (half(1.0)/half(2.0))*u0_B0(0,0,0)*wk10_B0(0,0,0) - (half(1.0)/half(2.0))*u1_B0(0,0,0)*wk17_B0(0,0,0) -
      (half(1.0)/half(2.0))*u2_B0(0,0,0)*wk34_B0(0,0,0);

    Residual4_B0(0,0,0) = -wk7_B0(0,0,0) - wk22_B0(0,0,0) - wk35_B0(0,0,0) - (half(1.0)/half(2.0))*wk4_B0(0,0,0) -
      (half(1.0)/half(2.0))*wk24_B0(0,0,0) - (half(1.0)/half(2.0))*wk28_B0(0,0,0) - (half(1.0)/half(2.0))*(wk9_B0(0,0,0) + wk23_B0(0,0,0) +
      wk38_B0(0,0,0))*rhoE_B0(0,0,0) - (half(1.0)/half(2.0))*u0_B0(0,0,0)*wk5_B0(0,0,0) - (half(1.0)/half(2.0))*u1_B0(0,0,0)*wk20_B0(0,0,0)
      - (half(1.0)/half(2.0))*u2_B0(0,0,0)*wk27_B0(0,0,0);

}

void opensbliblock00Kernel053(const ACC<float> &u0_B0, ACC<half> &wk1_B0)
{
    wk1_B0(0,0,0) = -(half(1.0)/half(12.0))*(-16*u0_B0(1,0,0) - 16*u0_B0(-1,0,0) + half(30)*u0_B0(0,0,0) + u0_B0(-2,0,0) +
      u0_B0(2,0,0))*inv2Delta0block0;

}

void opensbliblock00Kernel055(const ACC<float> &T_B0, ACC<half> &wk3_B0)
{
    wk3_B0(0,0,0) = -(half(1.0)/half(12.0))*(-16*T_B0(1,0,0) - 16*T_B0(-1,0,0) + half(30)*T_B0(0,0,0) + T_B0(-2,0,0) +
      T_B0(2,0,0))*inv2Delta0block0;

}

void opensbliblock00Kernel057(const ACC<float> &u2_B0, ACC<half> &wk5_B0)
{
   wk5_B0(0,0,0) = -(half(1.0)/half(12.0))*(-u2_B0(0,-2,0) - half(8)*u2_B0(0,1,0) + half(8)*u2_B0(0,-1,0) + u2_B0(0,2,0))*invDelta1block0;

}

void opensbliblock00Kernel058(const ACC<float> &u0_B0, ACC<half> &wk6_B0)
{
   wk6_B0(0,0,0) = -(half(1.0)/half(12.0))*(-u0_B0(0,-2,0) - half(8)*u0_B0(0,1,0) + half(8)*u0_B0(0,-1,0) + u0_B0(0,2,0))*invDelta1block0;

}

void opensbliblock00Kernel059(const ACC<float> &u2_B0, ACC<half> &wk7_B0)
{
    wk7_B0(0,0,0) = -(half(1.0)/half(12.0))*(-16*u2_B0(0,1,0) - 16*u2_B0(0,-1,0) + half(30)*u2_B0(0,0,0) + u2_B0(0,-2,0) +
      u2_B0(0,2,0))*inv2Delta1block0;

}

void opensbliblock00Kernel060(const ACC<float> &u1_B0, ACC<half> &wk8_B0)
{
    wk8_B0(0,0,0) = -(half(1.0)/half(12.0))*(-16*u1_B0(0,1,0) - 16*u1_B0(0,-1,0) + half(30)*u1_B0(0,0,0) + u1_B0(0,-2,0) +
      u1_B0(0,2,0))*inv2Delta1block0;

}

void opensbliblock00Kernel061(const ACC<float> &u1_B0, ACC<half> &wk9_B0)
{
    wk9_B0(0,0,0) = ((half(1.0)/half(12.0)))*(-u1_B0(0,0,-2) - u1_B0(0,0,2) - half(30)*u1_B0(0,0,0) + 16*u1_B0(0,0,1) +
      16*u1_B0(0,0,-1))*inv2Delta2block0;

}

void opensbliblock00Kernel063(const ACC<float> &u1_B0, ACC<half> &wk11_B0)
{
   wk11_B0(0,0,0) = ((half(1.0)/half(12.0)))*(-u1_B0(0,0,2) - half(8)*u1_B0(0,0,-1) + half(8)*u1_B0(0,0,1) + u1_B0(0,0,-2))*invDelta2block0;

}

void opensbliblock00Kernel064(const ACC<float> &u1_B0, ACC<half> &wk12_B0)
{
    wk12_B0(0,0,0) = -(half(1.0)/half(12.0))*(-16*u1_B0(1,0,0) - 16*u1_B0(-1,0,0) + half(30)*u1_B0(0,0,0) + u1_B0(-2,0,0) +
      u1_B0(2,0,0))*inv2Delta0block0;

}

void opensbliblock00Kernel065(const ACC<float> &u2_B0, ACC<half> &wk13_B0)
{
    wk13_B0(0,0,0) = -(half(1.0)/half(12.0))*(-16*u2_B0(0,0,1) - 16*u2_B0(0,0,-1) + half(30)*u2_B0(0,0,0) + u2_B0(0,0,-2) +
      u2_B0(0,0,2))*inv2Delta2block0;

}

void opensbliblock00Kernel066(const ACC<float> &u2_B0, ACC<half> &wk14_B0)
{
    wk14_B0(0,0,0) = -(half(1.0)/half(12.0))*(-16*u2_B0(1,0,0) - 16*u2_B0(-1,0,0) + half(30)*u2_B0(0,0,0) + u2_B0(-2,0,0) +
      u2_B0(2,0,0))*inv2Delta0block0;

}

void opensbliblock00Kernel067(const ACC<float> &u0_B0, ACC<half> &wk15_B0)
{
    wk15_B0(0,0,0) = -(half(1.0)/half(12.0))*(-16*u0_B0(0,0,1) - 16*u0_B0(0,0,-1) + half(30)*u0_B0(0,0,0) + u0_B0(0,0,-2) +
      u0_B0(0,0,2))*inv2Delta2block0;

}

void opensbliblock00Kernel068(const ACC<float> &u0_B0, ACC<half> &wk16_B0)
{
    wk16_B0(0,0,0) = -(half(1.0)/half(12.0))*(-16*u0_B0(0,1,0) - 16*u0_B0(0,-1,0) + half(30)*u0_B0(0,0,0) + u0_B0(0,-2,0) +
      u0_B0(0,2,0))*inv2Delta1block0;

}

void opensbliblock00Kernel069(const ACC<float> &u1_B0, ACC<half> &wk17_B0)
{
   wk17_B0(0,0,0) = -(half(1.0)/half(12.0))*(-u1_B0(-2,0,0) - half(8)*u1_B0(1,0,0) + half(8)*u1_B0(-1,0,0) + u1_B0(2,0,0))*invDelta0block0;

}

void opensbliblock00Kernel070(const ACC<float> &u1_B0, ACC<half> &wk18_B0)
{
   wk18_B0(0,0,0) = -(half(1.0)/half(12.0))*(-u1_B0(0,-2,0) - half(8)*u1_B0(0,1,0) + half(8)*u1_B0(0,-1,0) + u1_B0(0,2,0))*invDelta1block0;

}

void opensbliblock00Kernel073(const ACC<float> &T_B0, ACC<half> &wk21_B0)
{
    wk21_B0(0,0,0) = -(half(1.0)/half(12.0))*(-16*T_B0(0,1,0) - 16*T_B0(0,-1,0) + half(30)*T_B0(0,0,0) + T_B0(0,-2,0) +
      T_B0(0,2,0))*inv2Delta1block0;

}

void opensbliblock00Kernel074(const ACC<float> &u2_B0, ACC<half> &wk22_B0)
{
   wk22_B0(0,0,0) = -(half(1.0)/half(12.0))*(-u2_B0(-2,0,0) - half(8)*u2_B0(1,0,0) + half(8)*u2_B0(-1,0,0) + u2_B0(2,0,0))*invDelta0block0;

}

void opensbliblock00Kernel075(const ACC<float> &u0_B0, ACC<half> &wk23_B0)
{
   wk23_B0(0,0,0) = -(half(1.0)/half(12.0))*(-u0_B0(0,0,-2) - half(8)*u0_B0(0,0,1) + half(8)*u0_B0(0,0,-1) + u0_B0(0,0,2))*invDelta2block0;

}

void opensbliblock00Kernel076(const ACC<float> &u0_B0, ACC<half> &wk24_B0)
{
   wk24_B0(0,0,0) = -(half(1.0)/half(12.0))*(-u0_B0(-2,0,0) - half(8)*u0_B0(1,0,0) + half(8)*u0_B0(-1,0,0) + u0_B0(2,0,0))*invDelta0block0;

}

void opensbliblock00Kernel077(const ACC<float> &u2_B0, ACC<half> &wk25_B0)
{
   wk25_B0(0,0,0) = ((half(1.0)/half(12.0)))*(-u2_B0(0,0,2) - half(8)*u2_B0(0,0,-1) + half(8)*u2_B0(0,0,1) + u2_B0(0,0,-2))*invDelta2block0;

}

void opensbliblock00Kernel078(const ACC<float> &T_B0, ACC<half> &wk26_B0)
{
    wk26_B0(0,0,0) = -(half(1.0)/half(12.0))*(-16*T_B0(0,0,1) - 16*T_B0(0,0,-1) + half(30)*T_B0(0,0,0) + T_B0(0,0,-2) +
      T_B0(0,0,2))*inv2Delta2block0;

}

void opensbliblock00Kernel052(const ACC<half> &wk24_B0, ACC<half> &wk0_B0)
{
    wk0_B0(0,0,0) = -(half(1.0)/half(12.0))*(-wk24_B0(0,0,-2) - half(8)*wk24_B0(0,0,1) + half(8)*wk24_B0(0,0,-1) +
      wk24_B0(0,0,2))*invDelta2block0;

}

void opensbliblock00Kernel054(const ACC<half> &wk24_B0, ACC<half> &wk2_B0)
{
    wk2_B0(0,0,0) = -(half(1.0)/half(12.0))*(-wk24_B0(0,-2,0) - half(8)*wk24_B0(0,1,0) + half(8)*wk24_B0(0,-1,0) +
      wk24_B0(0,2,0))*invDelta1block0;

}

void opensbliblock00Kernel056(const ACC<half> &wk5_B0, ACC<half> &wk4_B0)
{
    wk4_B0(0,0,0) = ((half(1.0)/half(12.0)))*(-wk5_B0(0,0,2) - half(8)*wk5_B0(0,0,-1) + half(8)*wk5_B0(0,0,1) +
      wk5_B0(0,0,-2))*invDelta2block0;

}

void opensbliblock00Kernel062(const ACC<half> &wk22_B0, ACC<half> &wk10_B0)
{
    wk10_B0(0,0,0) = -(half(1.0)/half(12.0))*(-wk22_B0(0,0,-2) - half(8)*wk22_B0(0,0,1) + half(8)*wk22_B0(0,0,-1) +
      wk22_B0(0,0,2))*invDelta2block0;

}

void opensbliblock00Kernel071(const ACC<half> &wk17_B0, ACC<half> &wk19_B0)
{
    wk19_B0(0,0,0) = -(half(1.0)/half(12.0))*(-wk17_B0(0,-2,0) - half(8)*wk17_B0(0,1,0) + half(8)*wk17_B0(0,-1,0) +
      wk17_B0(0,2,0))*invDelta1block0;

}

void opensbliblock00Kernel072(const ACC<half> &wk18_B0, ACC<half> &wk20_B0)
{
    wk20_B0(0,0,0) = ((half(1.0)/half(12.0)))*(-wk18_B0(0,0,2) - half(8)*wk18_B0(0,0,-1) + half(8)*wk18_B0(0,0,1) +
      wk18_B0(0,0,-2))*invDelta2block0;

}

 void opensbliblock00Kernel080(const ACC<float> &u0_B0, const ACC<float> &u1_B0, const ACC<float> &u2_B0, const
ACC<half> &wk0_B0, const ACC<half> &wk10_B0, const ACC<half> &wk11_B0, const ACC<half> &wk12_B0, const ACC<half>
&wk13_B0, const ACC<half> &wk14_B0, const ACC<half> &wk15_B0, const ACC<half> &wk16_B0, const ACC<half> &wk17_B0, const
ACC<half> &wk18_B0, const ACC<half> &wk19_B0, const ACC<half> &wk1_B0, const ACC<half> &wk20_B0, const ACC<half>
&wk21_B0, const ACC<half> &wk22_B0, const ACC<half> &wk23_B0, const ACC<half> &wk24_B0, const ACC<half> &wk25_B0, const
ACC<half> &wk26_B0, const ACC<half> &wk2_B0, const ACC<half> &wk3_B0, const ACC<half> &wk4_B0, const ACC<half> &wk5_B0,
const ACC<half> &wk6_B0, const ACC<half> &wk7_B0, const ACC<half> &wk8_B0, const ACC<half> &wk9_B0, ACC<float>
&Residual1_B0, ACC<float> &Residual2_B0, ACC<float> &Residual3_B0, ACC<float> &Residual4_B0)
{
    Residual1_B0(0,0,0) = half(1.0)*(((half(1.0)/half(3.0)))*wk10_B0(0,0,0) + ((half(1.0)/half(3.0)))*wk19_B0(0,0,0) +
      ((half(4.0)/half(3.0)))*wk1_B0(0,0,0) + wk15_B0(0,0,0) + wk16_B0(0,0,0))*invRe + Residual1_B0(0,0,0);

    Residual2_B0(0,0,0) = half(1.0)*(((half(1.0)/half(3.0)))*wk2_B0(0,0,0) + ((half(1.0)/half(3.0)))*wk4_B0(0,0,0) + ((half(4.0)/half(3.0)))*wk8_B0(0,0,0)
      + wk9_B0(0,0,0) + wk12_B0(0,0,0))*invRe + Residual2_B0(0,0,0);

    Residual3_B0(0,0,0) = half(1.0)*(((half(1.0)/half(3.0)))*wk0_B0(0,0,0) + ((half(1.0)/half(3.0)))*wk20_B0(0,0,0) +
      ((half(4.0)/half(3.0)))*wk13_B0(0,0,0) + wk7_B0(0,0,0) + wk14_B0(0,0,0))*invRe + Residual3_B0(0,0,0);

    Residual4_B0(0,0,0) = half(1.0)*(wk5_B0(0,0,0) + wk11_B0(0,0,0))*invRe*wk5_B0(0,0,0) + half(1.0)*(wk5_B0(0,0,0) +
      wk11_B0(0,0,0))*invRe*wk11_B0(0,0,0) + half(1.0)*(wk6_B0(0,0,0) + wk17_B0(0,0,0))*invRe*wk6_B0(0,0,0) +
      half(1.0)*(wk6_B0(0,0,0) + wk17_B0(0,0,0))*invRe*wk17_B0(0,0,0) + half(1.0)*(wk22_B0(0,0,0) +
      wk23_B0(0,0,0))*invRe*wk22_B0(0,0,0) + half(1.0)*(wk22_B0(0,0,0) + wk23_B0(0,0,0))*invRe*wk23_B0(0,0,0) +
      half(1.0)*(-(half(2.0)/half(3.0))*wk18_B0(0,0,0) - (half(2.0)/half(3.0))*wk24_B0(0,0,0) +
      ((half(4.0)/half(3.0)))*wk25_B0(0,0,0))*invRe*wk25_B0(0,0,0) + half(1.0)*(-(half(2.0)/half(3.0))*wk18_B0(0,0,0) -
      (half(2.0)/half(3.0))*wk25_B0(0,0,0) + ((half(4.0)/half(3.0)))*wk24_B0(0,0,0))*invRe*wk24_B0(0,0,0) +
      half(1.0)*(-(half(2.0)/half(3.0))*wk24_B0(0,0,0) - (half(2.0)/half(3.0))*wk25_B0(0,0,0) +
      ((half(4.0)/half(3.0)))*wk18_B0(0,0,0))*invRe*wk18_B0(0,0,0) + half(1.0)*(((half(1.0)/half(3.0)))*wk0_B0(0,0,0) +
      ((half(1.0)/half(3.0)))*wk20_B0(0,0,0) + ((half(4.0)/half(3.0)))*wk13_B0(0,0,0) + wk7_B0(0,0,0) + wk14_B0(0,0,0))*invRe*u2_B0(0,0,0) +
      half(1.0)*(((half(1.0)/half(3.0)))*wk2_B0(0,0,0) + ((half(1.0)/half(3.0)))*wk4_B0(0,0,0) + ((half(4.0)/half(3.0)))*wk8_B0(0,0,0) + wk9_B0(0,0,0) +
      wk12_B0(0,0,0))*invRe*u1_B0(0,0,0) + half(1.0)*(((half(1.0)/half(3.0)))*wk10_B0(0,0,0) + ((half(1.0)/half(3.0)))*wk19_B0(0,0,0) +
      ((half(4.0)/half(3.0)))*wk1_B0(0,0,0) + wk15_B0(0,0,0) + wk16_B0(0,0,0))*invRe*u0_B0(0,0,0) + half(1.0)*(wk3_B0(0,0,0) +
      wk21_B0(0,0,0) + wk26_B0(0,0,0))*invPr*invRe*inv2Minf*inv_gamma_m1 + Residual4_B0(0,0,0);

}

 void opensbliblock00Kernel090(const ACC<float> &Residual0_B0, const ACC<float> &Residual1_B0, const ACC<float>
&Residual2_B0, const ACC<float> &Residual3_B0, const ACC<float> &Residual4_B0, const ACC<float> &rhoE_RKold_B0, const
ACC<float> &rho_RKold_B0, const ACC<float> &rhou0_RKold_B0, const ACC<float> &rhou1_RKold_B0, const ACC<float>
&rhou2_RKold_B0, ACC<float> &rhoE_B0, ACC<float> &rho_B0, ACC<float> &rhou0_B0, ACC<float> &rhou1_B0, ACC<float>
&rhou2_B0, const float *rknew)
{
   rho_B0(0,0,0) = rknew[0]*dt*Residual0_B0(0,0,0) + rho_RKold_B0(0,0,0);

   rhou0_B0(0,0,0) = rknew[0]*dt*Residual1_B0(0,0,0) + rhou0_RKold_B0(0,0,0);

   rhou1_B0(0,0,0) = rknew[0]*dt*Residual2_B0(0,0,0) + rhou1_RKold_B0(0,0,0);

   rhou2_B0(0,0,0) = rknew[0]*dt*Residual3_B0(0,0,0) + rhou2_RKold_B0(0,0,0);

   rhoE_B0(0,0,0) = rknew[0]*dt*Residual4_B0(0,0,0) + rhoE_RKold_B0(0,0,0);

}

 void opensbliblock00Kernel089(const ACC<float> &Residual0_B0, const ACC<float> &Residual1_B0, const ACC<float>
&Residual2_B0, const ACC<float> &Residual3_B0, const ACC<float> &Residual4_B0, ACC<float> &rhoE_RKold_B0, ACC<float>
&rho_RKold_B0, ACC<float> &rhou0_RKold_B0, ACC<float> &rhou1_RKold_B0, ACC<float> &rhou2_RKold_B0, const float *rkold)
{
   rho_RKold_B0(0,0,0) = rkold[0]*dt*Residual0_B0(0,0,0) + rho_RKold_B0(0,0,0);

   rhou0_RKold_B0(0,0,0) = rkold[0]*dt*Residual1_B0(0,0,0) + rhou0_RKold_B0(0,0,0);

   rhou1_RKold_B0(0,0,0) = rkold[0]*dt*Residual2_B0(0,0,0) + rhou1_RKold_B0(0,0,0);

   rhou2_RKold_B0(0,0,0) = rkold[0]*dt*Residual3_B0(0,0,0) + rhou2_RKold_B0(0,0,0);

   rhoE_RKold_B0(0,0,0) = rkold[0]*dt*Residual4_B0(0,0,0) + rhoE_RKold_B0(0,0,0);

}

#endif
