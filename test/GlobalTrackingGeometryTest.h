#ifndef GlobalTrackingGeometryTest_h
#define GlobalTrackingGeometryTest_h

/*
 * \class GlobalTrackingGeometryTest
 *
 * EDAnalyzer to test the GlobalTrackingGeometry.
 *
 *  $Date: 2006/05/09 16:36:00 $
 *  $Revision: 1.1 $
 *  \author M. Sani
 */
    
class GlobalTrackingGeometryTest : public edm::EDAnalyzer {

public:
 
    explicit GlobalTrackingGeometryTest( const edm::ParameterSet& );
    ~GlobalTrackingGeometryTest();

    virtual void analyze( const edm::Event&, const edm::EventSetup& );
 
    const std::string& myName() { return my_name;}

private: 
    
    std::string my_name;    

};

#endif
