#include <cxxtest/TestSuite.h>

#include <iostream>
#include <cstring>
using namespace std;

#include "Board.h"
#include "Auxiliar.h"

#include <iostream>


using namespace std;


class TestSuiteAC : public CxxTest::TestSuite, public Auxiliar {

 public:

  // Tests for Board ----------------------------------------------------
  void testBoard() {
  
     // constructor exception
     TS_ASSERT_THROWS_ASSERT(Board badSize(0), const std::invalid_argument &e, TS_ASSERT_EQUALS(strcmp(e.what(),"Wrong size"),0));
     
     Board brd(10);
     TS_ASSERT_EQUALS(brd.getSize(),10);
     
     Coordinate out(0,10);
     TS_ASSERT_EQUALS(brd.inside(out),false);
     TS_ASSERT_EQUALS(brd.getFighter(out)==NULL,true);
     
     Coordinate one(1,1),two(2,2),zero(0,0),nine(9,9);
     
     Fighter f35("F-35B","USS Eisenhower");
     Fighter f18("F-18","USS Eisenhower");
     
     Fighter sf1("SF-1","Spectra One");
     Fighter sf4("SF-4","Spectra One");
     
     TS_ASSERT_EQUALS(brd.launch(out,&f35),0); // outside of the board
     
     TS_ASSERT_EQUALS(brd.launch(one,&f35),0); // ok
     TS_ASSERT_EQUALS(f35.getPosition().getRow(),1);
     TS_ASSERT_EQUALS(f35.getPosition().getColumn(),1);
     TS_ASSERT_EQUALS(brd.getFighter(one)==&f35,true);
     
     TS_ASSERT_EQUALS(brd.launch(one,&f18),0); // one is occupied by a friend fighter (f35)
     TS_ASSERT_EQUALS(f18.getPosition().getRow(),-1);
     TS_ASSERT_EQUALS(f18.getPosition().getColumn(),-1);
     
     TS_ASSERT_EQUALS(brd.launch(zero,&f18),0); // one is occupied by a friend fighter (f35)
     TS_ASSERT_EQUALS(f18.getPosition().getRow(),0);
     TS_ASSERT_EQUALS(f18.getPosition().getColumn(),0);
     TS_ASSERT_EQUALS(brd.getFighter(zero)==&f18,true);

     TS_ASSERT_EQUALS(brd.launch(two,&f35),0); // f35 is yet on the board
     
     TS_ASSERT_EQUALS(brd.launch(nine,&sf1),0); // ok
     TS_ASSERT_EQUALS(sf1.getPosition().getRow(),9);
     TS_ASSERT_EQUALS(sf1.getPosition().getColumn(),9);
     TS_ASSERT_EQUALS(brd.getFighter(nine)==&sf1,true);
     
     TS_ASSERT_EQUALS(brd.launch(nine,&f35),0); // 'f35' is yet on the board

     srand(888);
     
     // sf4.fight(f18)     
     TS_ASSERT_EQUALS(brd.launch(zero,&sf4),1);
     
     stringstream ss;
     
     ss << f35;  
     TS_ASSERT_EQUALS(convertSS(ss),"(F-35B 1 [1,1] {100,80,80})");
     ss << f18;  
     TS_ASSERT_EQUALS(convertSS(ss),"(F-18 2 [-,-] {100,80,-3})");
     ss << sf1;  
     TS_ASSERT_EQUALS(convertSS(ss),"(SF-1 3 [9,9] {100,80,80})");
     ss << sf4;  
     TS_ASSERT_EQUALS(convertSS(ss),"(SF-4 4 [0,0] {100,80,4})");

     TS_ASSERT_EQUALS(brd.getFighter(zero)==&f18,false);
     TS_ASSERT_EQUALS(brd.getFighter(zero)==&sf4,true);
  }
};