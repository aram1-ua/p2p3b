#include <cxxtest/TestSuite.h>

#include <iostream>
#include <cstring>
using namespace std;

#include "Fighter.h"
#include "Auxiliar.h"

#include <iostream>


using namespace std;


class TestSuiteAC : public CxxTest::TestSuite, public Auxiliar {

 public:

  // Tests for Fighter ----------------------------------------------------
  void testFighter() {

     // Constructor + getters
     Fighter f35("F-35B","USS Nimitz");
     TS_ASSERT_EQUALS(f35.getType(),"F-35B");
     TS_ASSERT_EQUALS(f35.getSpeed(),100);
     TS_ASSERT_EQUALS(f35.getAttack(),80);
     TS_ASSERT_EQUALS(f35.getShield(),80);
     TS_ASSERT_EQUALS(f35.getId(),1);
     TS_ASSERT_EQUALS(f35.getAircraftCarrier(),"USS Nimitz");
     Coordinate pf35 = f35.getPosition();
     TS_ASSERT_EQUALS(pf35.getRow(),-1);
     TS_ASSERT_EQUALS(pf35.getColumn(),-1);

     // setters
     Coordinate otrapos(7,6);
     f35.setPosition(otrapos);
     pf35 = f35.getPosition();
     TS_ASSERT_EQUALS(pf35.getRow(),7);
     TS_ASSERT_EQUALS(pf35.getColumn(),6);
     
     f35.resetPosition();
     pf35 = f35.getPosition();
     TS_ASSERT_EQUALS(pf35.getRow(),-1);
     TS_ASSERT_EQUALS(pf35.getColumn(),-1);
     
     Fighter sf1("SF-1", "Spectra One");
     TS_ASSERT_EQUALS(sf1.getId(),2);
     
     sf1.setPosition(otrapos);
     sf1.addAttack(-220);
     TS_ASSERT_EQUALS(sf1.getAttack(),0);
     sf1.addAttack(80);
     TS_ASSERT_EQUALS(sf1.getAttack(),80);
     sf1.addAttack(220);
     TS_ASSERT_EQUALS(sf1.getAttack(),300);
     
     sf1.addSpeed(-101);
     TS_ASSERT_EQUALS(sf1.getSpeed(),0);
     sf1.addSpeed(200);
     TS_ASSERT_EQUALS(sf1.getSpeed(),200);
     
     sf1.addShield(-127);
     TS_ASSERT_EQUALS(sf1.getShield(),-47);
     
     // isDestroyed
     TS_ASSERT_EQUALS(sf1.isDestroyed(),true);
     TS_ASSERT_EQUALS(f35.isDestroyed(),false);
     sf1.addShield(107);
     TS_ASSERT_EQUALS(sf1.getShield(),60);
     TS_ASSERT_EQUALS(sf1.isDestroyed(),false);
     
     // getDamage
     int df35 = f35.getDamage(300);
     TS_ASSERT_EQUALS(df35,80);
     
     int dsf1 = sf1.getDamage(27);
     TS_ASSERT_EQUALS(dsf1,27);
     
     // operator<<
     stringstream ss;

     ss << f35;  
     TS_ASSERT_EQUALS(convertSS(ss),"(F-35B 1 [-,-] {100,80,80})");
     ss << sf1;  
     TS_ASSERT_EQUALS(convertSS(ss),"(SF-1 2 [7,6] {200,300,60})");

     // Constructor exception
     TS_ASSERT_THROWS_ASSERT(Fighter noType("",""), const std::invalid_argument &e, TS_ASSERT_EQUALS(strcmp(e.what(),"Wrong type"),0));
     
     Fighter blank(" ","");  // shoudn't throw the exception
     Fighter blbl(" "," ");  // neither
     ss << blank;  
     TS_ASSERT_EQUALS(convertSS(ss),"(  3 [-,-] {100,80,80})");
     ss << blbl;
     TS_ASSERT_EQUALS(convertSS(ss),"(  4 [-,-] {100,80,80})");
  }
  
  void testFailedFight() {

     // test fight  with one (or two) destroyed fighters, should return 0  
     Fighter destroOne("F-86","USS Eisenhower"), destroTwo("MIG-15","");
     
     destroOne.addShield(-80); // shield==0
     TS_ASSERT_EQUALS(destroOne.fight(&destroTwo),0);
     TS_ASSERT_EQUALS(destroTwo.fight(&destroOne),0);
     destroTwo.addShield(-80); // shield==0
     TS_ASSERT_EQUALS(destroOne.fight(&destroTwo),0);
     TS_ASSERT_EQUALS(destroTwo.fight(&destroOne),0);
  }
  
  void testFight() {

     Fighter::resetNextId(); 
  
     Fighter f35("F-35B","USS Nimitz");
     Fighter sf1("SF-1", "Spectra One");

     srand(888);
     TS_ASSERT_EQUALS(f35.fight(&sf1),1);  // f35 wins
     
     stringstream ss;
     ss << f35;  
     TS_ASSERT_EQUALS(convertSS(ss),"(F-35B 1 [-,-] {100,80,4})");
     ss << sf1;  
     TS_ASSERT_EQUALS(convertSS(ss),"(SF-1 2 [-,-] {100,80,-3})");
   
   
     Fighter f18("F-18","USS Nimitz");
     Fighter sf4("SF-4", "Spectra One");
     
     sf4.addSpeed(200);  //   300
     sf4.addAttack(1420); //  1500          

     srand(888);
     TS_ASSERT_EQUALS(f18.fight(&sf4),-1);  // sf4 wins
     
     ss << f18;  
     TS_ASSERT_EQUALS(convertSS(ss),"(F-18 3 [-,-] {100,80,-20})");
     ss << sf4;  
     TS_ASSERT_EQUALS(convertSS(ss),"(SF-4 4 [-,-] {300,1500,80})");
  }
};