#ifndef MBGL_ANDROID_JNI
#define MBGL_ANDROID_JNI

#include <string>
#include <vector>

// Forward definition of JNI types
typedef class _jclass* jclass;
typedef class _jstring* jstring;
typedef class _jobject* jobject;
typedef class _jlongArray* jlongArray;
typedef struct _jmethodID* jmethodID;
typedef struct _jfieldID* jfieldID;

struct _JavaVM;
typedef _JavaVM JavaVM;

struct _JNIEnv;
typedef _JNIEnv JNIEnv;

namespace mbgl {
namespace android {

extern JavaVM* theJVM;

extern std::string cachePath;
extern std::string dataPath;
extern std::string apkPath;
extern std::string androidRelease;

extern jmethodID onInvalidateId;
extern jmethodID onMapChangedId;
extern jmethodID onFpsChangedId;

extern jclass latLngClass;
extern jmethodID latLngConstructorId;
extern jfieldID latLngLatitudeId;
extern jfieldID latLngLongitudeId;

extern jclass latLngZoomClass;
extern jmethodID latLngZoomConstructorId;
extern jfieldID latLngZoomLatitudeId;
extern jfieldID latLngZoomLongitudeId;
extern jfieldID latLngZoomZoomId;

extern jclass bboxClass;
extern jmethodID bboxConstructorId;
extern jfieldID bboxLatNorthId;
extern jfieldID bboxLatSouthId;
extern jfieldID bboxLonEastId;
extern jfieldID bboxLonWestId;

extern jclass iconClass;
extern jfieldID iconIdId;

extern jclass markerClass;
extern jfieldID markerPositionId;
extern jfieldID markerIconId;

extern jclass polylineClass;
extern jfieldID polylineAlphaId;
extern jfieldID polylineColorId;
extern jfieldID polylineWidthId;
extern jfieldID polylinePointsId;

extern jclass polygonClass;
extern jfieldID polygonAlphaId;
extern jfieldID polygonFillColorId;
extern jfieldID polygonStrokeColorId;
extern jfieldID polygonPointsId;

extern jclass runtimeExceptionClass;
extern jclass nullPointerExceptionClass;

extern jmethodID listToArrayId;

extern jclass arrayListClass;
extern jmethodID arrayListConstructorId;
extern jmethodID arrayListAddId;

extern jclass projectedMetersClass;
extern jmethodID projectedMetersConstructorId;
extern jfieldID projectedMetersNorthingId;
extern jfieldID projectedMetersEastingId;

extern jclass pointFClass;
extern jmethodID pointFConstructorId;
extern jfieldID pointFXId;
extern jfieldID pointFYId;

extern jclass rectFClass;
extern jmethodID rectFConstructorId;
extern jfieldID rectFLeftId;
extern jfieldID rectFTopId;
extern jfieldID rectFRightId;
extern jfieldID rectFBottomId;

extern jclass httpContextClass;
extern jmethodID httpContextGetInstanceId;
extern jmethodID httpContextCreateRequestId;

extern jclass httpRequestClass;
extern jmethodID httpRequestStartId;
extern jmethodID httpRequestCancelId;

// Offline declarations start

extern jclass offlineManagerClass;
extern jfieldID offlineManagerClassPtrId;

extern jclass listOfflineRegionsCallbackClass;
extern jmethodID listOnListMethodId;
extern jmethodID listOnErrorMethodId;

extern jclass offlineRegionClass;
extern jfieldID offlineRegionOfflineManagerId;
extern jfieldID offlineRegionIdId;
extern jfieldID offlineRegionDefinitionId;
extern jfieldID offlineRegionMetadataId;
extern jfieldID offlineRegionPtrId;

extern jclass offlineRegionDefinitionClass;
extern jmethodID offlineRegionDefinitionConstructorId;
extern jfieldID offlineRegionDefinitionStyleURLId;
extern jfieldID offlineRegionDefinitionBoundsId;
extern jfieldID offlineRegionDefinitionMinZoomId;
extern jfieldID offlineRegionDefinitionMaxZoomId;
extern jfieldID offlineRegionDefinitionPixelRatioId;

extern jclass createOfflineRegionCallbackClass;
extern jmethodID createOnCreateMethodId;
extern jmethodID createOnErrorMethodId;

extern jclass offlineRegionObserverClass;
extern jmethodID offlineRegionObserveronStatusChangedId;
extern jmethodID offlineRegionObserveronErrorId;
extern jmethodID offlineRegionObserveronLimitId;

extern jclass offlineRegionStatusClass;
extern jmethodID offlineRegionStatusConstructorId;
extern jfieldID offlineRegionStatusDownloadStateId;
extern jfieldID offlineRegionStatusCompletedResourceCountId;
extern jfieldID offlineRegionStatusCompletedResourceSizeId;
extern jfieldID offlineRegionStatusRequiredResourceCountId;
extern jfieldID offlineRegionStatusRequiredResourceCountIsIndeterminateId;

extern jclass offlineRegionErrorClass;
extern jmethodID offlineRegionErrorConstructorId;
extern jfieldID offlineRegionErrorReasonId;
extern jfieldID offlineRegionErrorMessageId;

extern jclass offlineRegionStatusCallbackClass;
extern jmethodID offlineRegionStatusOnStatusId;
extern jmethodID offlineRegionStatusOnErrorId;

extern jclass offlineRegionDeleteCallbackClass;
extern jmethodID offlineRegionDeleteOnDeleteId;
extern jmethodID offlineRegionDeleteOnErrorId;

// Offline declarations end

extern bool throw_jni_error(JNIEnv *env, const char *msg);
extern bool attach_jni_thread(JavaVM* vm, JNIEnv** env, std::string threadName);
extern void detach_jni_thread(JavaVM* vm, JNIEnv** env, bool detach);
extern std::string std_string_from_jstring(JNIEnv *env, jstring jstr);
extern jstring std_string_to_jstring(JNIEnv *env, std::string str);
extern std::vector<std::string> std_vector_string_from_jobject(JNIEnv *env, jobject jlist);
extern jobject std_vector_string_to_jobject(JNIEnv *env, std::vector<std::string> vector);
extern jlongArray std_vector_uint_to_jobject(JNIEnv *env, std::vector<uint32_t> vector);

}
}

#endif
