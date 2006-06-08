/*
 * \file GlobalTrackingGeometryTest.cc
 *
 *  $Date: 2006/06/07 15:41:37 $
 *  $Revision: 1.2 $
 *  \author M. Sani
 */

#include <memory>

#include <FWCore/Framework/interface/Frameworkfwd.h>
#include <FWCore/Framework/interface/EDAnalyzer.h>
#include <FWCore/Framework/interface/Event.h>
#include <FWCore/Framework/interface/EventSetup.h>
#include <FWCore/Framework/interface/ESHandle.h>
#include <FWCore/Framework/interface/MakerMacros.h>
#include <FWCore/ParameterSet/interface/ParameterSet.h>

#include <Geometry/CommonDetUnit/test/GlobalTrackingGeometryTest.h>
#include <Geometry/CommonDetUnit/interface/GlobalTrackingGeometry.h>
#include <Geometry/Records/interface/GlobalTrackingGeometryRecord.h>

#include <Geometry/CSCGeometry/interface/CSCGeometry.h>
#include <Geometry/CSCGeometry/interface/CSCLayer.h>
#include <Geometry/DTGeometry/interface/DTGeometry.h>
#include <Geometry/DTGeometry/interface/DTLayer.h>
#include <Geometry/RPCGeometry/interface/RPCGeometry.h>
#include <Geometry/TrackerGeometryBuilder/interface/TrackerGeometry.h>

#include <DataFormats/DetId/interface/DetId.h>

#include <string>
#include <cmath>
#include <iomanip> 
#include <vector>

GlobalTrackingGeometryTest::GlobalTrackingGeometryTest( const edm::ParameterSet& iConfig )
 : my_name( "GlobalTrackingGeometryTest" ) {}

GlobalTrackingGeometryTest::~GlobalTrackingGeometryTest() {}

void GlobalTrackingGeometryTest::analyzeCSC(edm::ESHandle<CSCGeometry> cscGeometry, 
    edm::ESHandle<GlobalTrackingGeometry> geo) {

    for(CSCGeometry::DetUnitContainer::const_iterator itCSC = cscGeometry->detUnits().begin(); 
        itCSC != cscGeometry->detUnits().end(); itCSC++) {
        
        DetId detId = (*itCSC)->geographicalId();
        
        // Check idToDetUnit
        const GeomDetUnit* gdu = geo->idToDetUnit(detId);
	    assert(gdu == (*itCSC));
    }
    std::cout << "CSC detUnit: GlobalTrackingGeometry succesfully tested." << std::endl;
    
    for(CSCGeometry::DetContainer::const_iterator itCSC = cscGeometry->dets().begin(); 
        itCSC != cscGeometry->dets().end(); itCSC++) {
    
        DetId detId = (*itCSC)->geographicalId();
        
	    // Check idToDet
	    const GeomDet* gd = geo->idToDet(detId);
	    assert(gd == (*itCSC));
    }
    std::cout << "CSC det: GlobalTrackingGeometry succesfully tested." << std::endl;
}

void GlobalTrackingGeometryTest::analyzeDT(edm::ESHandle<DTGeometry> dtGeometry, 
    edm::ESHandle<GlobalTrackingGeometry> geo) {

    for(DTGeometry::DetUnitContainer::const_iterator itDT = dtGeometry->detUnits().begin(); 
        itDT != dtGeometry->detUnits().end(); itDT++) {
        
        DetId detId = (*itDT)->geographicalId();
        
        // Check idToDetUnit
        const GeomDetUnit* gdu = geo->idToDetUnit(detId);
	    assert(gdu == (*itDT));
    }
    std::cout << "DT detUnit: GlobalTrackingGeometry succesfully tested." << std::endl;
    
    for(DTGeometry::DetContainer::const_iterator itDT = dtGeometry->dets().begin(); 
        itDT != dtGeometry->dets().end(); itDT++) {
    
        DetId detId = (*itDT)->geographicalId();
        
	    // Check idToDet
	    const GeomDet* gd = geo->idToDet(detId);
	    assert(gd == (*itDT));
    }
    std::cout << "DT det: GlobalTrackingGeometry succesfully tested." << std::endl;
}

void GlobalTrackingGeometryTest::analyzeRPC(edm::ESHandle<RPCGeometry> rpcGeometry, edm::ESHandle<GlobalTrackingGeometry> geo) {

    for(RPCGeometry::DetUnitContainer::const_iterator itRPC = rpcGeometry->detUnits().begin(); 
        itRPC != rpcGeometry->detUnits().end(); itRPC++) {
        
        DetId detId = (*itRPC)->geographicalId();
        
        // Check idToDetUnit
        const GeomDetUnit* gdu = geo->idToDetUnit(detId);
	    assert(gdu == (*itRPC));
    }
    std::cout << "RPC detUnit: GlobalTrackingGeometry succesfully tested." << std::endl;
    
    for(RPCGeometry::DetContainer::const_iterator itRPC = rpcGeometry->dets().begin(); 
        itRPC != rpcGeometry->dets().end(); itRPC++) {
    
        DetId detId = (*itRPC)->geographicalId();

	    // Check idToDet
	    const GeomDet* gd = geo->idToDet(detId);
        assert(gd == (*itRPC));
    }
    std::cout << "RPC det: GlobalTrackingGeometry succesfully tested." << std::endl;
}

void GlobalTrackingGeometryTest::analyzeTracker(edm::ESHandle<TrackerGeometry> tkGeometry, 
    edm::ESHandle<GlobalTrackingGeometry> geo) {

    for(TrackerGeometry::DetUnitContainer::const_iterator itTk = tkGeometry->detUnits().begin(); 
        itTk != tkGeometry->detUnits().end(); itTk++) {
        
        DetId detId = (*itTk)->geographicalId();
        
        // Check idToDetUnit
        const GeomDetUnit* gdu = geo->idToDetUnit(detId);
	    assert(gdu == (*itTk));
    }
    std::cout << "Tracker detUnit: GlobalTrackingGeometry succesfully tested." << std::endl;
    
    for(TrackerGeometry::DetContainer::const_iterator itTk = tkGeometry->dets().begin(); 
        itTk != tkGeometry->dets().end(); itTk++) {
    
        DetId detId = (*itTk)->geographicalId();
        
	    // Check idToDet
	    const GeomDet* gd = geo->idToDet(detId);
	    assert(gd == (*itTk));
    }
    std::cout << "Tracker det: GlobalTrackingGeometry succesfully tested." << std::endl;
}

void GlobalTrackingGeometryTest::analyze( const edm::Event& iEvent, const edm::EventSetup& iSetup )
{
    std::cout << myName() << ": Analyzer..." << std::endl;

    edm::ESHandle<GlobalTrackingGeometry> geo;
    iSetup.get<GlobalTrackingGeometryRecord>().get(geo);     
    
    DetId detId1(DetId::Tracker, 0);
    std::cout << "Pointer to Tracker Geometry: ";
    std::cout << geo->slaveGeometry(detId1) << std::endl;
    
    DetId detId2(DetId::Muon, 1); 
    std::cout << "Pointer to DT Geometry: ";
    std::cout << geo->slaveGeometry(detId2) << std::endl;
 
    DetId detId3(DetId::Muon, 2); 
    std::cout << "Pointer to CSC Geometry: ";
    std::cout << geo->slaveGeometry(detId3) << std::endl;
 
    DetId detId4(DetId::Muon, 3); 
    std::cout << "Pointer to RPC Geometry: ";
    std::cout << geo->slaveGeometry(detId4) << std::endl;
        
    edm::ESHandle<CSCGeometry> cscGeometry;
    iSetup.get<MuonGeometryRecord>().get(cscGeometry);
  
    edm::ESHandle<DTGeometry> dtGeometry;
    iSetup.get<MuonGeometryRecord>().get(dtGeometry);
    
    edm::ESHandle<RPCGeometry> rpcGeometry;
    iSetup.get<MuonGeometryRecord>().get(rpcGeometry);

    edm::ESHandle<TrackerGeometry> tkGeometry;
    iSetup.get<TrackerDigiGeometryRecord>().get(tkGeometry);
    
    analyzeCSC(cscGeometry, geo);
    analyzeDT(dtGeometry, geo);
    analyzeRPC(rpcGeometry, geo);
    analyzeTracker(tkGeometry, geo);    
}

//define this as a plug-in
DEFINE_FWK_MODULE(GlobalTrackingGeometryTest)
