#include "AppProtocolRequestHandler.h"

AppProtocolRequestHandler::AppProtocolRequestHandler(Telescope& telescope): telescope(telescope){};

AppProtocolResponse AppProtocolRequestHandler::handle(AppProtocolRequest* request){
    switch (request->getType()){
    case AppProtocolRequests::Date:
        return this->onDateRequest(request);
    case AppProtocolRequests::Time:
        return this->onTimeRequest(request);
    case AppProtocolRequests::UtcOffset:
        return this->onUtcOffsetRequest(request);
    case AppProtocolRequests::Latitude: 
        return this->onLatitudeRequest(request);
    case AppProtocolRequests::Longitude:
        return this->onLongitudeRequest(request);
    case AppProtocolRequests::CalibrationDec:
        return this->onCalibrationDecRequest(request);
    case AppProtocolRequests::CalibrationRa:
        return this->onCalibrationRaRequest(request);
    case AppProtocolRequests::Move:
        return this->onMoveRequest(request);
    case AppProtocolRequests::ConstraintTop:
        return this->onConstraintTopRequest(request);
    case AppProtocolRequests::ConstraintBottom:
        return this->onConstraintBottomRequest(request);
    }
}

AppProtocolResponse AppProtocolRequestHandler::onTimeRequest(AppProtocolRequest* request){
    AppRequests::Time* time = dynamic_cast<AppRequests::Time*>(request);
    this->telescope.getCurrentDateTime().setTime(time->getRawData());
    return AppProtocolResponse::ok();
}

AppProtocolResponse AppProtocolRequestHandler::onDateRequest(AppProtocolRequest* request){
    AppRequests::Date* date = dynamic_cast<AppRequests::Date*>(request);
    this->telescope.getCurrentDateTime().setDate(date->getRawData());
    return AppProtocolResponse::ok();
}

AppProtocolResponse AppProtocolRequestHandler::onUtcOffsetRequest(AppProtocolRequest* request){
    AppRequests::UtcOffset* utcOffset = dynamic_cast<AppRequests::UtcOffset*>(request);
    this->telescope.getCurrentDateTime().setUtcOffset(utcOffset->getRawData());
    return AppProtocolResponse::ok();
}

AppProtocolResponse AppProtocolRequestHandler::onLatitudeRequest(AppProtocolRequest* request){
    AppRequests::Latitude* latitude = dynamic_cast<AppRequests::Latitude*>(request);
    this->telescope.getCurrentPosition().setLatitude(latitude->getRawData());
    return AppProtocolResponse::ok();
}

AppProtocolResponse AppProtocolRequestHandler::onLongitudeRequest(AppProtocolRequest* request){
    AppRequests::Longitude* longitude = dynamic_cast<AppRequests::Longitude*>(request);
    this->telescope.getCurrentPosition().setLongitude(longitude->getRawData());
    return AppProtocolResponse::ok();
}

AppProtocolResponse AppProtocolRequestHandler::onCalibrationDecRequest(AppProtocolRequest* request){
    AppRequests::CalibrationDec* calibrationDec = dynamic_cast<AppRequests::CalibrationDec*>(request);
    this->telescope.getLooksAt().getDec().update(calibrationDec->getRawData());
    return AppProtocolResponse::ok();
}

AppProtocolResponse AppProtocolRequestHandler::onCalibrationRaRequest(AppProtocolRequest* request){
    AppRequests::CalibrationRa* calibrationRa = dynamic_cast<AppRequests::CalibrationRa*>(request);
    this->telescope.getLooksAt().getRa().update(calibrationRa->getRawData());
    return AppProtocolResponse::ok();
}

AppProtocolResponse AppProtocolRequestHandler::onMoveRequest(AppProtocolRequest* request){
    AppRequests::Move* move = dynamic_cast<AppRequests::Move*>(request);
    return AppProtocolResponse::ok();
}

AppProtocolResponse AppProtocolRequestHandler::onConstraintTopRequest(AppProtocolRequest* request){
    AppRequests::ConstraintTop* constraintTop = dynamic_cast<AppRequests::ConstraintTop*>(request);
    this->telescope.getStepper1Constraints().setTopConstraint(); // todo second motor
    return AppProtocolResponse::ok();
}

AppProtocolResponse AppProtocolRequestHandler::onConstraintBottomRequest(AppProtocolRequest* request){
    AppRequests::ConstraintBottom* constraintBottom = dynamic_cast<AppRequests::ConstraintBottom*>(request);
    this->telescope.getStepper1Constraints().setBottomConstraint(); // todo second motor
    return AppProtocolResponse::ok();
}