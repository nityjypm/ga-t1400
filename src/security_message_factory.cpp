/**
 * @File     security_message_factory.cpp
 * @brief    
 * @DateTime 2018/8/4 11:36:40
 * @Author   Anyz
 */
#include "security_message_factory.h"
#include "security_rest.h"
#include "simple_xml.h"

/**
 * @Method   makeRegisterMessage
 * @Brief
 * @DateTime 2018-08-04T12:15:12+0800
 * @Modify   2018-08-04T12:15:12+0800
 * @Author   Anyz
 * @param    deviceId [description]
 * @return   [description]
 */
SecurityString security_message_factory::makeRegisterMessage(const char* deviceId) {
    simple_xml sx;
    sx.createRoot("Register");
    XMLNodeHandle node = sx.createNode("DeviceID");
	sx.setContent(node, deviceId);
    SecurityString sxml = sx.buildDoc(node);
    printf("%s\n", sxml.c_str());
    return sxml;
}
/**
 * @Method   makeUnregisterMessage
 * @Brief
 * @DateTime 2018-08-04T12:15:12+0800
 * @Modify   2018-08-04T12:15:12+0800
 * @Author   Anyz
 * @param    deviceId [description]
 * @return   [description]
 */
SecurityString security_message_factory::makeUnregisterMessage(const char* deviceId) {
    simple_xml sx;
    sx.createRoot("UnRegister");
    XMLNodeHandle node = sx.createNode("DeviceID");
	sx.setContent(node, deviceId);
    SecurityString sxml = sx.buildDoc(node);
    printf("%s\n", sxml.c_str());
    return sxml;
}
/**
 * @Method   makeKeepaliveMessage
 * @Brief
 * @DateTime 2018-08-04T12:15:12+0800
 * @Modify   2018-08-04T12:15:12+0800
 * @Author   Anyz
 * @param    deviceId [description]
 * @return   [description]
 */
SecurityString security_message_factory::makeKeepaliveMessage(const char* deviceId) {
    simple_xml sx;
    sx.createRoot("Keepalive");
    XMLNodeHandle node = sx.createNode("DeviceID");
	sx.setContent(node, deviceId);

    SecurityString sxml = sx.buildDoc(node);
    printf("%s\n", sxml.c_str());
    return sxml;
}

SecurityString security_message_factory::makeTimeMessage(const security_system_time_t* sysTime) {
    simple_xml sx;
    sx.createRoot("SysteimTime");
    XMLNodeHandle node1 = sx.createChild("VIIDServerID");
	if (!node1) {
		return SECURITY_STRING_EMPTY;
	}
	sx.setContent(node1, sysTime->viidServerId);

	XMLNodeHandle node2 = sx.createChild("TimeMode");
	if (!node2) {
		return SECURITY_STRING_EMPTY;
	}
	sx.setContent(node2, sysTime->timeMode);
	XMLNodeHandle node3 = sx.createChild("LocalTime");
	if (!node3) {
		return SECURITY_STRING_EMPTY;
	}
	sx.setContent(node3, sysTime->localTime);
	XMLNodeHandle node4 = sx.createChild("TimeZone");
	if (!node4) {
		return SECURITY_STRING_EMPTY;
	}
	sx.setContent(node4, sysTime->timeZone);

    SecurityString sxml = sx.buildDoc();

    printf("%s\n", sxml.c_str());

    return sxml;
}
/**
 * @Method   makeAPEListMessage
 * @Brief
 * @DateTime 2018-08-04T14:24:49+0800
 * @Modify   2018-08-04T14:24:49+0800
 * @Author   Anyz
 * @param    deviceId [description]
 * @return   [description]
 */
SecurityString security_message_factory::makeAPEListMessage() {
    simple_xml sx;
    sx.createRoot("complexType", "name", "APEList");
    XMLNodeHandle node = sx.createNode("sequence");
    XMLNodeHandle node1 = sx.createChild(node, "element");
    sx.addProperity(node1, "name", "APEObject");
    sx.addProperity(node1, "type", "APE");
    sx.addProperity(node1, "minOccurs", num2String(0));
    SecurityString sxml = sx.buildDoc(node);
    printf("%s\n", sxml.c_str());
    return sxml;
}
/**
 * @Method   makeVideoSliceListMessage
 * @Brief
 * @DateTime 2018-08-06T11:18:46+0800
 * @Modify   2018/8/6 12:27:22
 * @Author   Anyz
 * @param    minOccurs [description]
 * @param    maxOccurs [description]
 * @return   [description]
 */
SecurityString security_message_factory::makeVideoSliceListMessage(const security_videoslice_t* videoSlice) {
    simple_xml sx;
    sx.createRoot("VideoSliceList");
    XMLNodeHandle node = sx.createNode("VideoSlice");

    XMLNodeHandle subnode1 = sx.createChild(node, "VideoSliceInfo");
    sx.setContent(subnode1, SECURITY_STRING_EMPTY);

	XMLNodeHandle subnode2 = sx.createChild(node, "PersonList");
	sx.setContent(subnode2, SECURITY_STRING_EMPTY);

	XMLNodeHandle subnode3 = sx.createChild(node, "FaceList");
	sx.setContent(subnode3, SECURITY_STRING_EMPTY);

	XMLNodeHandle subnode4 = sx.createChild(node, "MotorVehicleList");
	sx.setContent(subnode4, SECURITY_STRING_EMPTY);

	XMLNodeHandle subnode5 = sx.createChild(node, "NonMotorVehicleList");
	sx.setContent(subnode5, SECURITY_STRING_EMPTY);

	XMLNodeHandle subnode6 = sx.createChild(node, "ThingList");
	sx.setContent(subnode6, SECURITY_STRING_EMPTY);

	XMLNodeHandle subnode7 = sx.createChild(node, "SceneList");
	sx.setContent(subnode7, SECURITY_STRING_EMPTY);

	XMLNodeHandle subnode8 = sx.createChild(node, "Data");
	sx.setContent(subnode8, SECURITY_STRING_EMPTY);

    SecurityString sxml = sx.buildDoc(node);
    printf("%s\n", sxml.c_str());
    return sxml;
}

SecurityString security_message_factory::makeVideoSliceInfoListMessage() {
	return SECURITY_STRING_EMPTY;
}
/**
 * @Method   makeImageListMessage
 * @Brief
 * @DateTime 2018-08-06T12:27:15+0800
 * @Modify   2018-08-06T12:27:15+0800
 * @Author   Anyz
 * @param    minOccurs [description]
 * @param    maxOccurs [description]
 * @return   [description]
 */
SecurityString security_message_factory::makeImageListMessage(security_images_t& imageList) {
    simple_xml sx;
    sx.createRoot("complexType", "name", "ImageList");
    XMLNodeHandle node = sx.createNode("sequence");
    XMLNodeHandle node1 = sx.createChild(node, "element");
    sx.addProperity(node1, "name", "Image");
    sx.addProperity(node1, "minOccurs", num2String(1));

    XMLNodeHandle subnode = sx.createChild(node, "complexType");

    XMLNodeHandle subnode1 = sx.createChild(subnode, "element");
    sx.addProperity(subnode1, "name", "ImageInfo");
    sx.addProperity(subnode1, "type", "ImageInfo");
    sx.addProperity(subnode1, "minOccurs", num2String(1));
    sx.addProperity(subnode1, "maxOccurs", num2String(1));

    XMLNodeHandle subnode2 = sx.createChild(subnode, "element");
    sx.addProperity(subnode2, "name", "PersonList");
    sx.addProperity(subnode2, "minOccurs", num2String(1));
    sx.addProperity(subnode2, "maxOccurs", num2String(1));
    XMLNodeHandle subnode3 = sx.createChild(subnode, "element");
    sx.addProperity(subnode3, "name", "FaceList");
    sx.addProperity(subnode3, "minOccurs", num2String(1));
    sx.addProperity(subnode3, "maxOccurs", num2String(1));
    XMLNodeHandle subnode4 = sx.createChild(subnode, "element");
    sx.addProperity(subnode4, "name", "MotorVehicleList");
    sx.addProperity(subnode4, "minOccurs", num2String(1));
    sx.addProperity(subnode4, "maxOccurs", num2String(1));
    XMLNodeHandle subnode5 = sx.createChild(subnode, "element");
    sx.addProperity(subnode5, "name", "NonMotorVehicleList");
    sx.addProperity(subnode5, "minOccurs", num2String(1));
    sx.addProperity(subnode5, "maxOccurs", num2String(1));
    XMLNodeHandle subnode6 = sx.createChild(subnode, "element");
    sx.addProperity(subnode6, "name", "ThingList");
    sx.addProperity(subnode6, "minOccurs", num2String(1));
    sx.addProperity(subnode6, "maxOccurs", num2String(1));
    XMLNodeHandle subnode7 = sx.createChild(subnode, "element");
    sx.addProperity(subnode7, "name", "SceneList");
    sx.addProperity(subnode7, "minOccurs", num2String(1));
    sx.addProperity(subnode7, "maxOccurs", num2String(1));

    XMLNodeHandle subnode8 = sx.createChild(subnode, "element");
    sx.addProperity(subnode8, "name", "Data");
    sx.addProperity(subnode8, "type", "base64Binary");
    sx.addProperity(subnode8, "minOccurs", num2String(1));
    sx.addProperity(subnode8, "maxOccurs", num2String(1));

    SecurityString sxml = sx.buildDoc(node);
    printf("%s\n", sxml.c_str());
    return sxml;
}
/**
 * @Method   makeImageMessage
 * @Brief
 * @DateTime 2018-08-06T15:49:27+0800
 * @Modify   2018-08-06T15:49:27+0800
 * @Author   Anyz
 * @param    info [description]
 * @return   [description]
 */
SecurityString security_message_factory::makeImageObjectMessage(const security_image_t* info) {
    simple_xml sx;
    sx.createRoot("complexType", "name", "ImageInfo");
    XMLNodeHandle node = sx.createNode("sequence");
    XMLNodeHandle node1 = sx.createChild(node, "element");
    sx.addProperity(node1, "name", "ImageID");
    sx.addProperity(node1, "type", "BasicObjectIdType");
    sx.addProperity(node1, "use", "required");
    XMLNodeHandle node2 = sx.createChild(node, "element");
    sx.addProperity(node2, "name", "InfoKind");
    sx.addProperity(node2, "type", "InfoType");
    sx.addProperity(node2, "use", "required");
    //...


    SecurityString sxml = sx.buildDoc(node);
    printf("%s\n", sxml.c_str());
    return sxml;
}

SecurityString security_message_factory::makeImageInfoMessage(const security_image_info_t* imageInfo) {
	return SECURITY_STRING_EMPTY;
}

SecurityString security_message_factory::makeFileObjectMessage(const security_file_t* fo) {
    simple_xml sx;
    sx.createRoot("complexType", "name", "File");
    XMLNodeHandle node = sx.createNode("sequence");
    XMLNodeHandle node1 = sx.createChild(node, "element");
    sx.addProperity(node1, "name", "FileID");
    sx.addProperity(node1, "type", "BasicObjectIdType");
    XMLNodeHandle node2 = sx.createChild(node, "element");
    sx.addProperity(node2, "name", "InfoKind");
    sx.addProperity(node2, "type", "DataSourceType");
    sx.addProperity(node2, "use", "required");
    // ...


    SecurityString sxml = sx.buildDoc(node);
    printf("%s\n", sxml.c_str());
    return sxml;
}
/**
 * @Method   makeFileListMessage
 * @Brief
 * @DateTime 2018-08-06T15:49:40+0800
 * @Modify   2018-08-06T15:49:40+0800
 * @Author   Anyz
 * @param    fo [description]
 * @return   [description]
 */
SecurityString security_message_factory::makeFileListMessage(security_files_t& fileList) {
    simple_xml sx;
    sx.createRoot("complexType", "name", "Fileist");
    XMLNodeHandle node = sx.createNode("sequence");
    XMLNodeHandle node1 = sx.createChild(node, "element");
    sx.addProperity(node1, "name", "FileObject");
    sx.addProperity(node1, "type", "File");
    sx.addProperity(node1, "minOccurs", "0");

    SecurityString sxml = sx.buildDoc(node);
    printf("%s\n", sxml.c_str());
    return sxml;
}
/**
 * @Method   makeFileInfoMessage
 * @Brief    xml not defined ???
 * @DateTime 2018-08-06T16:21:26+0800
 * @Modify   2018-08-06T16:21:26+0800
 * @Author   Anyz
 * @param    fo [description]
 * @return   [description]
 */
SecurityString security_message_factory::makeFileInfoMessage(const security_file_info_t* fo) {
    simple_xml sx;
    sx.createRoot("complexType", "name", "FileInfo");
    XMLNodeHandle node = sx.createNode("sequence");
    XMLNodeHandle node1 = sx.createChild(node, "element");
    sx.addProperity(node1, "name", "FileId");
    sx.addProperity(node1, "type", "File");

    SecurityString sxml = sx.buildDoc(node);
    printf("%s\n", sxml.c_str());
    return sxml;
}
/**
 * @Method   makePersonListMessage
 * @Brief
 * @DateTime 2018-08-06T17:08:03+0800
 * @Modify   2018-08-06T17:08:03+0800
 * @Author   Anyz
 * @param    personList [description]
 * @return   [description]
 */
SecurityString security_message_factory::makePersonListMessage(security_persons_t& personList) {
    simple_xml sx;
    sx.createRoot("complexType", "name", "PersonList");
    XMLNodeHandle node = sx.createNode("sequence");
    XMLNodeHandle node1 = sx.createChild(node, "element");
    sx.addProperity(node1, "name", "PersonObject");
    sx.addProperity(node1, "type", "Person");
    sx.addProperity(node1, "minOccurs", "0");

    SecurityString sxml = sx.buildDoc(node);
    printf("%s\n", sxml.c_str());
    return sxml;
}
/**
 * @Method   makePersonObjMessage
 * @Brief
 * @DateTime 2018-08-06T17:08:17+0800
 * @Modify   2018-08-06T17:08:17+0800
 * @Author   Anyz
 * @param    personList [description]
 * @return   [description]
 */
SecurityString security_message_factory::makePersonObjectMessage(const security_person_t* personObject) {
    simple_xml sx;
    sx.createRoot("complexType", "name", "Person");
    XMLNodeHandle node = sx.createNode("sequence");
    XMLNodeHandle node1 = sx.createChild(node, "element");
    sx.addProperity(node1, "name", "PersonID");
    sx.addProperity(node1, "type", "ImageCntObjectIdType");

    XMLNodeHandle node2 = sx.createChild(node, "element");
    sx.addProperity(node2, "name", "InfoKind");
    sx.addProperity(node2, "type", "InfoType");
    sx.addProperity(node2, "use", "required");
    // ...


    SecurityString sxml = sx.buildDoc(node);
    printf("%s\n", sxml.c_str());
    return sxml;
}

SecurityString security_message_factory::makeFaceListMessage(security_faces_t& faceList) {
    return SECURITY_STRING_EMPTY;
}

SecurityString security_message_factory::makeFaceMessage(const security_face_t* faceObject) {
    return SECURITY_STRING_EMPTY;
}

SecurityString security_message_factory::makeMotorVehicleListMessage(security_motorvehicles_t& motorVehicleList) {
    return SECURITY_STRING_EMPTY;
}

SecurityString security_message_factory::makeMotorVehicleMessage(const security_motorvehicle_t* motorVehicle) {
    return SECURITY_STRING_EMPTY;
}

SecurityString security_message_factory::makeNonMotorVehicleListMessage(security_nonmotorvehicles_t& motorVehicleList) {
    return SECURITY_STRING_EMPTY;
}

SecurityString security_message_factory::makeNonMotorVehicleMessage(const security_nonmotorvehicle_t* nonmotorVehicle) {
    return SECURITY_STRING_EMPTY;
}

SecurityString security_message_factory::makeThingListMessage(security_things_t& thingList) {
    return SECURITY_STRING_EMPTY;
}

SecurityString security_message_factory::makeThingMessage(const security_thing_t* thingObject) {
    return SECURITY_STRING_EMPTY;
}

SecurityString security_message_factory::makeSceneListMessage(security_scenes_t& sceneList) {
    return SECURITY_STRING_EMPTY;
}

SecurityString security_message_factory::makeSceneMessage(const security_scene_t* scemeObject) {
    return SECURITY_STRING_EMPTY;
}

SecurityString security_message_factory::makeCaseListMessage(security_cases_t& caseList) {
    return SECURITY_STRING_EMPTY;
}

SecurityString security_message_factory::makeCaseMessage(const security_case_t* caseObject) {
    return SECURITY_STRING_EMPTY;
}

SecurityString security_message_factory::makeCaseInfoMessage(const security_caseinfo_t* caseInfo) {
    return SECURITY_STRING_EMPTY;
}

SecurityString security_message_factory::makeDispositionMessage(const security_disposition_t* disp) {
    return SECURITY_STRING_EMPTY;
}
SecurityString security_message_factory::makeDispositionListMessage(security_dispositions_t& dispList) {
	return SECURITY_STRING_EMPTY;
}

SecurityString security_message_factory::makeDispositionNotifyMessage(const security_disposition_notify_t* dispNoti) {
    return SECURITY_STRING_EMPTY;
}
SecurityString security_message_factory::makeDispositionNotifyListMessage(security_disposition_notifys_t& dispNotifyList) {
	return SECURITY_STRING_EMPTY;
}

SecurityString security_message_factory::makeSubscribeListMessage(security_subscribes_t& subscribeList) {
    return SECURITY_STRING_EMPTY;
}
SecurityString security_message_factory::makeSubscribeNotifyListMessage(security_subscribe_notifys_t& subscribeNotifyList) {
	return SECURITY_STRING_EMPTY;
}

SecurityString security_message_factory::makeAnalysisRuleListMessage(security_analysis_rules_t& analysisRuleList) {
    return SECURITY_STRING_EMPTY;
}

SecurityString security_message_factory::makeAnalysisRuleMessage(const security_analysis_rule_t* analysisRule) {
    return SECURITY_STRING_EMPTY;
}

SecurityString security_message_factory::makeVideoLabelListMessage(security_videolabels_t& videoLabelList) {
    return SECURITY_STRING_EMPTY;
}

SecurityString security_message_factory::makeVideoLabelMessage(const security_videolabel_t* videoLabel) {
    return SECURITY_STRING_EMPTY;
}












