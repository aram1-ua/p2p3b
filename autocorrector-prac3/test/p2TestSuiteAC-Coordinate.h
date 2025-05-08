#include <cxxtest/TestSuite.h>

#include <iostream>
#include <cstring>
using namespace std;

#include "Coordinate.h"

#include "Auxiliar.h"

#include <iostream>


using namespace std;


class TestSuiteAC : public CxxTest::TestSuite, public Auxiliar {

 public:

  // Tests for Coordinate ----------------------------------------------------
  void testCoordinate() {
  
    // Constructores + getters
    Coordinate empty;
    TS_ASSERT_EQUALS(empty.getRow(),-1);
    TS_ASSERT_EQUALS(empty.getColumn(),-1);

    Coordinate good(1,0);
    TS_ASSERT_EQUALS(good.getRow(),1);
    TS_ASSERT_EQUALS(good.getColumn(),0);

    Coordinate wrong(7,-54);
    TS_ASSERT_EQUALS(wrong.getRow(),7);
    TS_ASSERT_EQUALS(wrong.getColumn(),-54);

    Coordinate wrong2(-7,54);
    TS_ASSERT_EQUALS(wrong2.getRow(),-7);
    TS_ASSERT_EQUALS(wrong2.getColumn(),54);
    
    // isValid
    TS_ASSERT_EQUALS(empty.isValid(),false);
    TS_ASSERT_EQUALS(good.isValid(),true);
    TS_ASSERT_EQUALS(wrong.isValid(),false);
    TS_ASSERT_EQUALS(wrong2.isValid(),false);

    // setters
    wrong.setColumn(55);  
    TS_ASSERT_EQUALS(wrong.getColumn(),55);
    TS_ASSERT_EQUALS(wrong.isValid(),true);  // se convierte en válida

    wrong2.setRow(-1);        
    TS_ASSERT_EQUALS(wrong2.getRow(),-1);
    TS_ASSERT_EQUALS(wrong2.isValid(),false);
    
    // reset
    wrong.reset();
    TS_ASSERT_EQUALS(wrong.getRow(),-1);
    TS_ASSERT_EQUALS(wrong.getColumn(),-1);
    TS_ASSERT_EQUALS(wrong.isValid(),false);

    // operator<<    
    stringstream ss;

    ss << empty;  
    TS_ASSERT_EQUALS(convertSS(ss),"[-,-]");
    ss << good;
    TS_ASSERT_EQUALS(convertSS(ss),"[1,0]");
    ss << wrong;
    TS_ASSERT_EQUALS(convertSS(ss),"[-,-]");
    ss << wrong2;
    TS_ASSERT_EQUALS(convertSS(ss),"[-,-]");
  }
  
};

