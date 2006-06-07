#ifndef GlobalTrackingGeometryTest_h
#define GlobalTrackingGeometryTest_h

/*
 * \class GlobalTrackingGeometryTest
 *
 * EDAnalyzer to test the GlobalTrackingGeometry.
 *
 *  $Date: 2006/05/10 17:59:46 $
 *  $Revision: 1.1 $
 *  \author M. Sani
 */

class CSCGeometry;
class DTGeometry;    
class RPCGeometry;
class TrackerGeometry;
class GlobalTrackingGeometry;
    
class GlobalTrackingGeometryTest : public edm::EDAnalyzer {

public:
 
    explicit GlobalTrackingGeometryTest( const edm::ParameterSet& );
    ~GlobalTrackingGeometryTest();

    virtual void analyze( const edm::Event&, const edm::EventSetup& );
    void analyzeCSC(edm::ESHandle<CSCGeometry> cscGeometry, edm::ESHandle<GlobalTrackingGeometry> geo);
    void analyzeDT(edm::ESHandle<DTGeometry> cscGeometry, edm::ESHandle<GlobalTrackingGeometry> geo);
    void analyzeRPC(edm::ESHandle<RPCGeometry> cscGeometry, edm::ESHandle<GlobalTrackingGeometry> geo);
    void analyzeTracker(edm::ESHandle<TrackerGeometry> tkGeometry, edm::ESHandle<GlobalTrackingGeometry> geo);
         
    const std::string& myName() { return my_name; }

private: 
    
    std::string my_name;    

};

#endif
