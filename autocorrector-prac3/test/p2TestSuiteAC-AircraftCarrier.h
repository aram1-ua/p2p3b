#include <cxxtest/TestSuite.h>

#include <iostream>
#include <cstring>
using namespace std;

#include "AircraftCarrier.h"
#include "Auxiliar.h"

#include <iostream>


using namespace std;


class TestSuiteAC : public CxxTest::TestSuite, public Auxiliar {

 public:

  // Tests for AircraftCarrier ----------------------------------------------------
  void testAircraftCarrier() {

     // constructor + getters
     AircraftCarrier nim("USS Nimitz");
     
     TS_ASSERT_EQUALS(nim.getName(),"USS Nimitz");

     vector<Fighter *>nimfl = nim.getFleet();
     TS_ASSERT_EQUALS(nimfl.size(),0);
     
     TS_ASSERT_EQUALS(nim.getFirstAvailableFighter("")==NULL,true);
     TS_ASSERT_EQUALS(nim.myFleet(),"");
     
     // constructor exception
     TS_ASSERT_THROWS_ASSERT(AircraftCarrier noName(""), const std::invalid_argument &e, TS_ASSERT_EQUALS(strcmp(e.what(),"Wrong name"),0));

     // addFighters + showFleet
     nim.addFighters("5/F-35B:12/F-18:3/A6:2/F-35B");
     
     istringstream in_stream;
     ostringstream out_stream;

     in_stream.str("");
     out_stream.str("");
     redirectStreams(in_stream,out_stream);

     nim.showFleet();
     restoreStreams();
     string nfl = out_stream.str();
     
     TS_ASSERT_EQUALS(rmb(nfl),rmb("(F-35B 1 [-,-] {100,80,80})(F-35B 2 [-,-] {100,80,80})(F-35B 3 [-,-] {100,80,80})(F-35B 4 [-,-] {100,80,80})(F-35B 5 [-,-] {100,80,80})(F-18 6 [-,-] {100,80,80})(F-18 7 [-,-] {100,80,80})(F-18 8 [-,-] {100,80,80})(F-18 9 [-,-] {100,80,80})(F-18 10 [-,-] {100,80,80})(F-18 11 [-,-] {100,80,80})(F-18 12 [-,-] {100,80,80})(F-18 13 [-,-] {100,80,80})(F-18 14 [-,-] {100,80,80})(F-18 15 [-,-] {100,80,80})(F-18 16 [-,-] {100,80,80})(F-18 17 [-,-] {100,80,80})(A6 18 [-,-] {100,80,80})(A6 19 [-,-] {100,80,80})(A6 20 [-,-] {100,80,80})(F-35B 21 [-,-] {100,80,80})(F-35B 22 [-,-] {100,80,80})"));

     // myFleet + updateResults + operator<<
     TS_ASSERT_EQUALS(nim.myFleet(),"7/F-35B:12/F-18:3/A6");
     
     nim.updateResults(7);
     nim.updateResults(-1);
     nim.updateResults(-7);
     nim.updateResults(1);
     nim.updateResults(1);
     nim.updateResults(1);
   
     stringstream ss;

     ss << nim;  
     TS_ASSERT_EQUALS(convertSS(ss),"Aircraft Carrier [USS Nimitz 3/1] 7/F-35B:12/F-18:3/A6");
  }
  
  void testBattle() {
     
     Fighter::resetNextId();
     
     AircraftCarrier lin("USS Abraham Lincoln");
     
     
     lin.addFighters("3/F-35B:2/F-18");
     vector<Fighter *>lfl = lin.getFleet();
     TS_ASSERT_EQUALS(lfl.size(),5);
     
     Coordinate pos(3,4);
     lfl[0]->setPosition(pos);  // position one fighter
     lfl[1]->addShield(-85);    // destroy second fighter
     
     istringstream in_stream;
     ostringstream out_stream;

     in_stream.str("");
     out_stream.str("");
     redirectStreams(in_stream,out_stream);
     lin.showFleet();
     restoreStreams();
     string slfl = out_stream.str();
     
     TS_ASSERT_EQUALS(rmb(slfl),rmb("(F-35B 1 [3,4] {100,80,80})(F-35B 2 [-,-] {100,80,-5})(X)(F-35B 3 [-,-] {100,80,80})(F-18 4 [-,-] {100,80,80})(F-18 5 [-,-] {100,80,80})"));
     
     // getFirstAvailableFighter
     
     Fighter *f35_3 = lin.getFirstAvailableFighter("F-35B");
     TS_ASSERT_EQUALS(lfl[2],f35_3);
     f35_3->addShield(-100);
     TS_ASSERT_EQUALS(lin.getFirstAvailableFighter("F-35B")==NULL,true);
     
     Fighter *f18 = lin.getFirstAvailableFighter("");
     TS_ASSERT_EQUALS(lfl[3],f18);
     TS_ASSERT_EQUALS(lfl[3],lin.getFirstAvailableFighter("F-18"));
     f18->addShield(-120);
     lfl[4]->addShield(-200);
     TS_ASSERT_EQUALS(lin.getFirstAvailableFighter("")==NULL,true);
     
     in_stream.str("");
     out_stream.str("");
     redirectStreams(in_stream,out_stream);
     lin.showFleet();
     restoreStreams();
     slfl = out_stream.str();
     TS_ASSERT_EQUALS(rmb(slfl),rmb("(F-35B 1 [3,4] {100,80,80})(F-35B 2 [-,-] {100,80,-5})(X)(F-35B 3 [-,-] {100,80,-20})(X)(F-18 4 [-,-] {100,80,-40})(X)(F-18 5 [-,-] {100,80,-120})(X)"));
     
     // purgeFleet
     TS_ASSERT_EQUALS(lin.purgeFleet(),4);
     
     in_stream.str("");
     out_stream.str("");
     redirectStreams(in_stream,out_stream);
     lin.showFleet();
     restoreStreams();
     slfl = out_stream.str();
     TS_ASSERT_EQUALS(rmb(slfl),rmb("(F-35B 1 [3,4] {100,80,80})"));
     
     stringstream ss;

     ss << lin;  
     TS_ASSERT_EQUALS(convertSS(ss),"Aircraft Carrier [USS Abraham Lincoln 0/0] 1/F-35B");
     
     lin.addFighters("3/A6");

     in_stream.str("");
     out_stream.str("");
     redirectStreams(in_stream,out_stream);
     lin.showFleet();
     restoreStreams();
     slfl = out_stream.str();
     TS_ASSERT_EQUALS(rmb(slfl),rmb("(F-35B 1 [3,4] {100,80,80})(A6 6 [-,-] {100,80,80})(A6 7 [-,-] {100,80,80})(A6 8 [-,-] {100,80,80})"));
     
     ss << lin;  
     TS_ASSERT_EQUALS(convertSS(ss),"Aircraft Carrier [USS Abraham Lincoln 0/0] 1/F-35B:3/A6");
     
  }
};
