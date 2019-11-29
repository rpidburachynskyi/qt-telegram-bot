QT -= gui
QT += network
CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp \
    passport/telegramencryptedcredentials.cpp \
    passport/telegramencryptedpassportelement.cpp \
    passport/telegrampassportdata.cpp \
    passport/telegrampassportfile.cpp \
    payments/telegramanswerprecheckoutquery.cpp \
    payments/telegramanswershippingquery.cpp \
    payments/telegraminvoice.cpp \
    payments/telegramlabeledprice.cpp \
    payments/telegramorderinfo.cpp \
    payments/telegramprecheckoutquery.cpp \
    payments/telegramshipingoption.cpp \
    payments/telegramshippingaddress.cpp \
    payments/telegramshippingquery.cpp \
    payments/telegramsuccessfulpayment.cpp \
    stickers/telegrammaskposition.cpp \
    stickers/telegramsticker.cpp \
    stickers/telegramstickerset.cpp \
        telegrambot.cpp \
    telegramrequest.cpp \
    telegramrequestdownload.cpp \
    types/itelegrammessagekeyboard.cpp \
    types/telegramanimation.cpp \
    types/telegramaudio.cpp \
    types/telegramchat.cpp \
    types/telegramchatmember.cpp \
    types/telegramchatpermissions.cpp \
    types/telegramchatphoto.cpp \
    types/telegramcontact.cpp \
    types/telegramdocument.cpp \
    types/telegramfile.cpp \
    types/telegramforcereply.cpp \
    types/telegraminlinekeyboardbutton.cpp \
    types/telegraminlinekeyboardmarkup.cpp \
    types/telegraminputmedia.cpp \
    types/telegraminputmediaanimation.cpp \
    types/telegraminputmediaaudio.cpp \
    types/telegraminputmediadocument.cpp \
    types/telegraminputmediaphoto.cpp \
    types/telegraminputmediavideo.cpp \
    types/telegramkeyboardbutton.cpp \
    types/telegramleftnewchatmember.cpp \
    types/telegramlocation.cpp \
    types/telegrammessage.cpp \
    types/telegrammessageentity.cpp \
    types/telegramphotosize.cpp \
    types/telegrampoll.cpp \
    types/telegrampolloption.cpp \
    types/telegramreplykeyboardmarkup.cpp \
    types/telegramreplykeyboardremove.cpp \
    types/telegramresponseparameters.cpp \
    types/telegramresult.cpp \
    types/telegramresults.cpp \
    types/telegramupdate.cpp \
    types/telegramuser.cpp \
    types/telegramuserprofilephotos.cpp \
    types/telegramvenue.cpp \
    types/telegramvideo.cpp \
    types/telegramvideonote.cpp \
    types/telegramvoice.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    passport/telegramencryptedcredentials.h \
    passport/telegramencryptedpassportelement.h \
    passport/telegrampassportdata.h \
    passport/telegrampassportfile.h \
    payments/telegramanswerprecheckoutquery.h \
    payments/telegramanswershippingquery.h \
    payments/telegraminvoice.h \
    payments/telegramlabeledprice.h \
    payments/telegramorderinfo.h \
    payments/telegramprecheckoutquery.h \
    payments/telegramshipingoption.h \
    payments/telegramshippingaddress.h \
    payments/telegramshippingquery.h \
    payments/telegramsuccessfulpayment.h \
    stickers/telegrammaskposition.h \
    stickers/telegramsticker.h \
    stickers/telegramstickerset.h \
    telegrambot.h \
    telegramrequest.h \
    telegramrequestdownload.h \
    types/itelegrammessagekeyboard.h \
    types/telegramanimation.h \
    types/telegramaudio.h \
    types/telegramchat.h \
    types/telegramchatmember.h \
    types/telegramchatpermissions.h \
    types/telegramchatphoto.h \
    types/telegramcontact.h \
    types/telegramdocument.h \
    types/telegramfile.h \
    types/telegramforcereply.h \
    types/telegraminlinekeyboardbutton.h \
    types/telegraminlinekeyboardmarkup.h \
    types/telegraminputmedia.h \
    types/telegraminputmediaanimation.h \
    types/telegraminputmediaaudio.h \
    types/telegraminputmediadocument.h \
    types/telegraminputmediaphoto.h \
    types/telegraminputmediavideo.h \
    types/telegramkeyboardbutton.h \
    types/telegramleftnewchatmember.h \
    types/telegramlocation.h \
    types/telegrammessage.h \
    types/telegrammessageentity.h \
    types/telegramphotosize.h \
    types/telegrampoll.h \
    types/telegrampolloption.h \
    types/telegramreplykeyboardmarkup.h \
    types/telegramreplykeyboardremove.h \
    types/telegramresponseparameters.h \
    types/telegramresult.h \
    types/telegramresults.h \
    types/telegramupdate.h \
    types/telegramuser.h \
    types/telegramuserprofilephotos.h \
    types/telegramvenue.h \
    types/telegramvideo.h \
    types/telegramvideonote.h \
    types/telegramvoice.h
