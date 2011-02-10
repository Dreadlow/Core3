/*
 *	server/zone/objects/area/MissionReconActiveArea.cpp generated by engine3 IDL compiler 0.60
 */

#include "MissionReconActiveArea.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "server/zone/objects/player/PlayerCreature.h"

#include "server/zone/objects/mission/ReconMissionObjective.h"

/*
 *	MissionReconActiveAreaStub
 */

MissionReconActiveArea::MissionReconActiveArea() : ActiveArea(DummyConstructorParameter::instance()) {
	MissionReconActiveAreaImplementation* _implementation = new MissionReconActiveAreaImplementation();
	_impl = _implementation;
	_impl->_setStub(this);
}

MissionReconActiveArea::MissionReconActiveArea(DummyConstructorParameter* param) : ActiveArea(param) {
}

MissionReconActiveArea::~MissionReconActiveArea() {
}


void MissionReconActiveArea::notifyEnter(SceneObject* player) {
	MissionReconActiveAreaImplementation* _implementation = (MissionReconActiveAreaImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		_implementation->notifyEnter(player);
}

void MissionReconActiveArea::setMissionObjective(ReconMissionObjective* mission) {
	MissionReconActiveAreaImplementation* _implementation = (MissionReconActiveAreaImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);
		method.addObjectParameter(mission);

		method.executeWithVoidReturn();
	} else
		_implementation->setMissionObjective(mission);
}

DistributedObjectServant* MissionReconActiveArea::_getImplementation() {

	_updated = true;
	return _impl;
}

void MissionReconActiveArea::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;
}

/*
 *	MissionReconActiveAreaImplementation
 */

MissionReconActiveAreaImplementation::MissionReconActiveAreaImplementation(DummyConstructorParameter* param) : ActiveAreaImplementation(param) {
	_initializeImplementation();
}


MissionReconActiveAreaImplementation::~MissionReconActiveAreaImplementation() {
}


void MissionReconActiveAreaImplementation::finalize() {
}

void MissionReconActiveAreaImplementation::_initializeImplementation() {
	_setClassHelper(MissionReconActiveAreaHelper::instance());

	_serializationHelperMethod();
	_serializationHelperMethod();
}

void MissionReconActiveAreaImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (MissionReconActiveArea*) stub;
	ActiveAreaImplementation::_setStub(stub);
}

DistributedObjectStub* MissionReconActiveAreaImplementation::_getStub() {
	return _this;
}

MissionReconActiveAreaImplementation::operator const MissionReconActiveArea*() {
	return _this;
}

void MissionReconActiveAreaImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void MissionReconActiveAreaImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void MissionReconActiveAreaImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void MissionReconActiveAreaImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void MissionReconActiveAreaImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void MissionReconActiveAreaImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void MissionReconActiveAreaImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void MissionReconActiveAreaImplementation::_serializationHelperMethod() {
	ActiveAreaImplementation::_serializationHelperMethod();

	_setClassName("MissionReconActiveArea");

}

void MissionReconActiveAreaImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint16 _varSize = stream->readShort();

		int _currentOffset = stream->getOffset();

		if(MissionReconActiveAreaImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool MissionReconActiveAreaImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (ActiveAreaImplementation::readObjectMember(stream, _name))
		return true;

	if (_name == "missionObjective") {
		TypeInfo<ManagedWeakReference<ReconMissionObjective* > >::parseFromBinaryStream(&missionObjective, stream);
		return true;
	}


	return false;
}

void MissionReconActiveAreaImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = MissionReconActiveAreaImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int MissionReconActiveAreaImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	String _name;
	int _offset;
	uint16 _totalSize;
	_name = "missionObjective";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<ManagedWeakReference<ReconMissionObjective* > >::toBinaryStream(&missionObjective, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);


	return 1 + ActiveAreaImplementation::writeObjectMembers(stream);
}

MissionReconActiveAreaImplementation::MissionReconActiveAreaImplementation() {
	_initializeImplementation();
	// server/zone/objects/area/MissionReconActiveArea.idl(57):  		missionObjective = null;
	missionObjective = NULL;
	// server/zone/objects/area/MissionReconActiveArea.idl(59):  		Logger.setLoggingName("MissionReconActiveArea");
	Logger::setLoggingName("MissionReconActiveArea");
}

void MissionReconActiveAreaImplementation::notifyEnter(SceneObject* player) {
	// server/zone/objects/area/MissionReconActiveArea.idl(63):  		Logger.info("notifyEnter mission recon", true);
	Logger::info("notifyEnter mission recon", true);
	// server/zone/objects/area/MissionReconActiveArea.idl(65):  
	if (!player->isPlayerCreature()){
	// server/zone/objects/area/MissionReconActiveArea.idl(66):  			return;
	return;
}

	else {
	// server/zone/objects/area/MissionReconActiveArea.idl(68):  
	if (missionObjective != NULL){
	// server/zone/objects/area/MissionReconActiveArea.idl(69):  				PlayerCreature missionOwner = missionObjective.getPlayerOwner();
	PlayerCreature* missionOwner = missionObjective->getPlayerOwner();
	// server/zone/objects/area/MissionReconActiveArea.idl(71):  			}
	if ((PlayerCreature*) player == missionOwner){
	// server/zone/objects/area/MissionReconActiveArea.idl(72):  					missionObjective.complete();
	missionObjective->complete();
}
}

	else {
	// server/zone/objects/area/MissionReconActiveArea.idl(75):  				super.removeFromZone();
	ActiveAreaImplementation::removeFromZone();
}
}
}

void MissionReconActiveAreaImplementation::setMissionObjective(ReconMissionObjective* mission) {
	// server/zone/objects/area/MissionReconActiveArea.idl(81):  		missionObjective = mission;
	missionObjective = mission;
}

/*
 *	MissionReconActiveAreaAdapter
 */

MissionReconActiveAreaAdapter::MissionReconActiveAreaAdapter(MissionReconActiveAreaImplementation* obj) : ActiveAreaAdapter(obj) {
}

Packet* MissionReconActiveAreaAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		notifyEnter((SceneObject*) inv->getObjectParameter());
		break;
	case 7:
		setMissionObjective((ReconMissionObjective*) inv->getObjectParameter());
		break;
	default:
		return NULL;
	}

	return resp;
}

void MissionReconActiveAreaAdapter::notifyEnter(SceneObject* player) {
	((MissionReconActiveAreaImplementation*) impl)->notifyEnter(player);
}

void MissionReconActiveAreaAdapter::setMissionObjective(ReconMissionObjective* mission) {
	((MissionReconActiveAreaImplementation*) impl)->setMissionObjective(mission);
}

/*
 *	MissionReconActiveAreaHelper
 */

MissionReconActiveAreaHelper* MissionReconActiveAreaHelper::staticInitializer = MissionReconActiveAreaHelper::instance();

MissionReconActiveAreaHelper::MissionReconActiveAreaHelper() {
	className = "MissionReconActiveArea";

	Core::getObjectBroker()->registerClass(className, this);
}

void MissionReconActiveAreaHelper::finalizeHelper() {
	MissionReconActiveAreaHelper::finalize();
}

DistributedObject* MissionReconActiveAreaHelper::instantiateObject() {
	return new MissionReconActiveArea(DummyConstructorParameter::instance());
}

DistributedObjectServant* MissionReconActiveAreaHelper::instantiateServant() {
	return new MissionReconActiveAreaImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* MissionReconActiveAreaHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new MissionReconActiveAreaAdapter((MissionReconActiveAreaImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

