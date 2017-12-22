#include "IRSensor.h"
#include "PinConfiguration.h"

Logger *IRSensor::LOG = Logger::createLogger("IRSensor");

IRCode IRSensor::readCode() {

    IRCode code = NONE;
    if (irrecv.decode(&results)) {
        code = translateIR();
        LOG->newLine()
                ->logAppend("Read code: ")
                ->logAppend(code)
                ->logAppend(" current code")
                ->logAppend(currentCode);

        irrecv.resume();
    }

    if (code == NONE || code == REPEAT_) {
        return currentCode;
    }

    LOG->newLine()->logAppend("Change current code ")->logAppend(currentCode)->logAppend(" to ")->logAppend(code);

    currentCode = code;
    return currentCode;
}

void IRSensor::consumeLastCode() {
    LOG->newLine()->logAppend("Consume ")->logAppend(currentCode);
    currentCode = NONE;
}

IRCode IRSensor::translateIR() {
    switch (results.value) {
        case 0xFFA25D:
            return IRCode::POWER;
        case 0xFFE21D:
            return IRCode::FUNC_STOP;
        case 0xFF629D:
            return IRCode::VOL_UP;
        case 0xFF22DD:
            return IRCode::FAST_BACK;
        case 0xFF02FD:
            return IRCode::PAUSE;
        case 0xFFC23D:
            return IRCode::FAST_FORWARD;
        case 0xFFE01F:
            return IRCode::DOWN;
        case 0xFFA857:
            return IRCode::VOL_DOWN;
        case 0xFF906F:
            return IRCode::UP;
        case 0xFF9867:
            return IRCode::EQ;
        case 0xFFB04F:
            return IRCode::ST_REPT;
        case 0xFF6897:
            return IRCode::NUMBER_0;
        case 0xFF30CF:
            return IRCode::NUMBER_1;
        case 0xFF18E7:
            return IRCode::NUMBER_2;
        case 0xFF7A85:
            return IRCode::NUMBER_3;
        case 0xFF10EF:
            return IRCode::NUMBER_4;
        case 0xFF38C7:
            return IRCode::NUMBER_5;
        case 0xFF5AA5:
            return IRCode::NUMBER_6;
        case 0xFF42BD:
            return IRCode::NUMBER_7;
        case 0xFF4AB5:
            return IRCode::NUMBER_8;
        case 0xFF52AD:
            return IRCode::NUMBER_9;
        case 0xFFFFFFFF:
            return IRCode::REPEAT_;
        default:
            return IRCode::NONE;
    }
}

IRSensor::IRSensor() : irrecv(IRReceiverPins::y) {
    IRSensor::irrecv.enableIRIn();
}
