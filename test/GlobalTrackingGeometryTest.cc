/*
 * \file GlobalTrackingGeometryTest.cc
 *
 *  $Date: 2006/05/09 16:36:00 $
 *  $Revision: 1.1 $
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

#include <DataFormats/DetId/interface/DetId.h>

#include <string>
#include <cmath>
#include <iomanip> 
#include <vector>



GlobalTrackingGeometryTest::GlobalTrackingGeometryTest( const edm::ParameterSet& iConfig )
 : my_name( "GlobalTrackingGeometryTest" ) {}


GlobalTrackingGeometryTest::~GlobalTrackingGeometryTest() {}

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
}

//define this as a plug-in
DEFINE_FWK_MODULE(GlobalTrackingGeometryTest)
