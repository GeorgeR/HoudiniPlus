#include "HappyPrivatePCH.h"
#include "HoudiniAPI.h"

FHoudiniApi::CreateInProcessSessionFuncPtr FHoudiniApi::CreateInProcessSession = &FHoudiniApi::CreateInProcessSessionEmptyStub;

FHoudiniApi::StartThriftSocketServerFuncPtr FHoudiniApi::StartThriftSocketServer = &FHoudiniApi::StartThriftSocketServerEmptyStub;

FHoudiniApi::CreateThriftSocketSessionFuncPtr FHoudiniApi::CreateThriftSocketSession = &FHoudiniApi::CreateThriftSocketSessionEmptyStub;

FHoudiniApi::StartThriftNamedPipeServerFuncPtr FHoudiniApi::StartThriftNamedPipeServer = &FHoudiniApi::StartThriftNamedPipeServerEmptyStub;

FHoudiniApi::CreateThriftNamedPipeSessionFuncPtr FHoudiniApi::CreateThriftNamedPipeSession = &FHoudiniApi::CreateThriftNamedPipeSessionEmptyStub;

FHoudiniApi::BindCustomImplementationFuncPtr FHoudiniApi::BindCustomImplementation = &FHoudiniApi::BindCustomImplementationEmptyStub;

FHoudiniApi::CreateCustomSessionFuncPtr FHoudiniApi::CreateCustomSession = &FHoudiniApi::CreateCustomSessionEmptyStub;

FHoudiniApi::IsSessionValidFuncPtr FHoudiniApi::IsSessionValid = &FHoudiniApi::IsSessionValidEmptyStub;

FHoudiniApi::CloseSessionFuncPtr FHoudiniApi::CloseSession = &FHoudiniApi::CloseSessionEmptyStub;

FHoudiniApi::IsInitializedFuncPtr FHoudiniApi::IsInitialized = &FHoudiniApi::IsInitializedEmptyStub;

FHoudiniApi::InitializeFuncPtr FHoudiniApi::Initialize = &FHoudiniApi::InitializeEmptyStub;

FHoudiniApi::CleanupFuncPtr FHoudiniApi::Cleanup = &FHoudiniApi::CleanupEmptyStub;

FHoudiniApi::GetEnvIntFuncPtr FHoudiniApi::GetEnvInt = &FHoudiniApi::GetEnvIntEmptyStub;

FHoudiniApi::GetSessionEnvIntFuncPtr FHoudiniApi::GetSessionEnvInt = &FHoudiniApi::GetSessionEnvIntEmptyStub;

FHoudiniApi::GetServerEnvIntFuncPtr FHoudiniApi::GetServerEnvInt = &FHoudiniApi::GetServerEnvIntEmptyStub;

FHoudiniApi::GetServerEnvStringFuncPtr FHoudiniApi::GetServerEnvString = &FHoudiniApi::GetServerEnvStringEmptyStub;

FHoudiniApi::SetServerEnvIntFuncPtr FHoudiniApi::SetServerEnvInt = &FHoudiniApi::SetServerEnvIntEmptyStub;

FHoudiniApi::SetServerEnvStringFuncPtr FHoudiniApi::SetServerEnvString = &FHoudiniApi::SetServerEnvStringEmptyStub;

FHoudiniApi::GetStatusFuncPtr FHoudiniApi::GetStatus = &FHoudiniApi::GetStatusEmptyStub;

FHoudiniApi::GetStatusStringBufLengthFuncPtr FHoudiniApi::GetStatusStringBufLength = &FHoudiniApi::GetStatusStringBufLengthEmptyStub;

FHoudiniApi::GetStatusStringFuncPtr FHoudiniApi::GetStatusString = &FHoudiniApi::GetStatusStringEmptyStub;

FHoudiniApi::ComposeNodeCookResultFuncPtr FHoudiniApi::ComposeNodeCookResult = &FHoudiniApi::ComposeNodeCookResultEmptyStub;

FHoudiniApi::GetComposedNodeCookResultFuncPtr FHoudiniApi::GetComposedNodeCookResult = &FHoudiniApi::GetComposedNodeCookResultEmptyStub;

FHoudiniApi::CheckForSpecificErrorsFuncPtr FHoudiniApi::CheckForSpecificErrors = &FHoudiniApi::CheckForSpecificErrorsEmptyStub;

FHoudiniApi::GetCookingTotalCountFuncPtr FHoudiniApi::GetCookingTotalCount = &FHoudiniApi::GetCookingTotalCountEmptyStub;

FHoudiniApi::GetCookingCurrentCountFuncPtr FHoudiniApi::GetCookingCurrentCount = &FHoudiniApi::GetCookingCurrentCountEmptyStub;

FHoudiniApi::ConvertTransformFuncPtr FHoudiniApi::ConvertTransform = &FHoudiniApi::ConvertTransformEmptyStub;

FHoudiniApi::ConvertMatrixToQuatFuncPtr FHoudiniApi::ConvertMatrixToQuat = &FHoudiniApi::ConvertMatrixToQuatEmptyStub;

FHoudiniApi::ConvertMatrixToEulerFuncPtr FHoudiniApi::ConvertMatrixToEuler = &FHoudiniApi::ConvertMatrixToEulerEmptyStub;

FHoudiniApi::ConvertTransformQuatToMatrixFuncPtr FHoudiniApi::ConvertTransformQuatToMatrix = &FHoudiniApi::ConvertTransformQuatToMatrixEmptyStub;

FHoudiniApi::ConvertTransformEulerToMatrixFuncPtr FHoudiniApi::ConvertTransformEulerToMatrix = &FHoudiniApi::ConvertTransformEulerToMatrixEmptyStub;

FHoudiniApi::PythonThreadInterpreterLockFuncPtr FHoudiniApi::PythonThreadInterpreterLock = &FHoudiniApi::PythonThreadInterpreterLockEmptyStub;

FHoudiniApi::GetStringBufLengthFuncPtr FHoudiniApi::GetStringBufLength = &FHoudiniApi::GetStringBufLengthEmptyStub;

FHoudiniApi::GetStringFuncPtr FHoudiniApi::GetString = &FHoudiniApi::GetStringEmptyStub;

FHoudiniApi::GetStringBatchSizeFuncPtr FHoudiniApi::GetStringBatchSize = &FHoudiniApi::GetStringBatchSizeEmptyStub;

FHoudiniApi::GetStringBatchFuncPtr FHoudiniApi::GetStringBatch = &FHoudiniApi::GetStringBatchEmptyStub;

FHoudiniApi::GetTimeFuncPtr FHoudiniApi::GetTime = &FHoudiniApi::GetTimeEmptyStub;

FHoudiniApi::SetTimeFuncPtr FHoudiniApi::SetTime = &FHoudiniApi::SetTimeEmptyStub;

FHoudiniApi::GetTimelineOptionsFuncPtr FHoudiniApi::GetTimelineOptions = &FHoudiniApi::GetTimelineOptionsEmptyStub;

FHoudiniApi::SetTimelineOptionsFuncPtr FHoudiniApi::SetTimelineOptions = &FHoudiniApi::SetTimelineOptionsEmptyStub;

FHoudiniApi::LoadAssetLibraryFromFileFuncPtr FHoudiniApi::LoadAssetLibraryFromFile = &FHoudiniApi::LoadAssetLibraryFromFileEmptyStub;

FHoudiniApi::LoadAssetLibraryFromMemoryFuncPtr FHoudiniApi::LoadAssetLibraryFromMemory = &FHoudiniApi::LoadAssetLibraryFromMemoryEmptyStub;

FHoudiniApi::GetAvailableAssetCountFuncPtr FHoudiniApi::GetAvailableAssetCount = &FHoudiniApi::GetAvailableAssetCountEmptyStub;

FHoudiniApi::GetAvailableAssetsFuncPtr FHoudiniApi::GetAvailableAssets = &FHoudiniApi::GetAvailableAssetsEmptyStub;

FHoudiniApi::GetAssetInfoFuncPtr FHoudiniApi::GetAssetInfo = &FHoudiniApi::GetAssetInfoEmptyStub;

FHoudiniApi::InterruptFuncPtr FHoudiniApi::Interrupt = &FHoudiniApi::InterruptEmptyStub;

FHoudiniApi::LoadHIPFileFuncPtr FHoudiniApi::LoadHIPFile = &FHoudiniApi::LoadHIPFileEmptyStub;

FHoudiniApi::SaveHIPFileFuncPtr FHoudiniApi::SaveHIPFile = &FHoudiniApi::SaveHIPFileEmptyStub;

FHoudiniApi::IsNodeValidFuncPtr FHoudiniApi::IsNodeValid = &FHoudiniApi::IsNodeValidEmptyStub;

FHoudiniApi::GetNodeInfoFuncPtr FHoudiniApi::GetNodeInfo = &FHoudiniApi::GetNodeInfoEmptyStub;

FHoudiniApi::GetNodePathFuncPtr FHoudiniApi::GetNodePath = &FHoudiniApi::GetNodePathEmptyStub;

FHoudiniApi::GetManagerNodeIdFuncPtr FHoudiniApi::GetManagerNodeId = &FHoudiniApi::GetManagerNodeIdEmptyStub;

FHoudiniApi::ComposeChildNodeListFuncPtr FHoudiniApi::ComposeChildNodeList = &FHoudiniApi::ComposeChildNodeListEmptyStub;

FHoudiniApi::GetComposedChildNodeListFuncPtr FHoudiniApi::GetComposedChildNodeList = &FHoudiniApi::GetComposedChildNodeListEmptyStub;

FHoudiniApi::CreateNodeFuncPtr FHoudiniApi::CreateNode = &FHoudiniApi::CreateNodeEmptyStub;

FHoudiniApi::CreateInputNodeFuncPtr FHoudiniApi::CreateInputNode = &FHoudiniApi::CreateInputNodeEmptyStub;

FHoudiniApi::CookNodeFuncPtr FHoudiniApi::CookNode = &FHoudiniApi::CookNodeEmptyStub;

FHoudiniApi::DeleteNodeFuncPtr FHoudiniApi::DeleteNode = &FHoudiniApi::DeleteNodeEmptyStub;

FHoudiniApi::RenameNodeFuncPtr FHoudiniApi::RenameNode = &FHoudiniApi::RenameNodeEmptyStub;

FHoudiniApi::ConnectNodeInputFuncPtr FHoudiniApi::ConnectNodeInput = &FHoudiniApi::ConnectNodeInputEmptyStub;

FHoudiniApi::DisconnectNodeInputFuncPtr FHoudiniApi::DisconnectNodeInput = &FHoudiniApi::DisconnectNodeInputEmptyStub;

FHoudiniApi::QueryNodeInputFuncPtr FHoudiniApi::QueryNodeInput = &FHoudiniApi::QueryNodeInputEmptyStub;

FHoudiniApi::GetNodeInputNameFuncPtr FHoudiniApi::GetNodeInputName = &FHoudiniApi::GetNodeInputNameEmptyStub;

FHoudiniApi::DisconnectNodeOutputsAtFuncPtr FHoudiniApi::DisconnectNodeOutputsAt = &FHoudiniApi::DisconnectNodeOutputsAtEmptyStub;

FHoudiniApi::QueryNodeOutputConnectedCountFuncPtr FHoudiniApi::QueryNodeOutputConnectedCount = &FHoudiniApi::QueryNodeOutputConnectedCountEmptyStub;

FHoudiniApi::QueryNodeOutputConnectedNodesFuncPtr FHoudiniApi::QueryNodeOutputConnectedNodes = &FHoudiniApi::QueryNodeOutputConnectedNodesEmptyStub;

FHoudiniApi::GetNodeOutputNameFuncPtr FHoudiniApi::GetNodeOutputName = &FHoudiniApi::GetNodeOutputNameEmptyStub;

FHoudiniApi::GetParametersFuncPtr FHoudiniApi::GetParameters = &FHoudiniApi::GetParametersEmptyStub;

FHoudiniApi::GetParmInfoFuncPtr FHoudiniApi::GetParmInfo = &FHoudiniApi::GetParmInfoEmptyStub;

FHoudiniApi::GetParmIdFromNameFuncPtr FHoudiniApi::GetParmIdFromName = &FHoudiniApi::GetParmIdFromNameEmptyStub;

FHoudiniApi::GetParmInfoFromNameFuncPtr FHoudiniApi::GetParmInfoFromName = &FHoudiniApi::GetParmInfoFromNameEmptyStub;

FHoudiniApi::GetParmTagNameFuncPtr FHoudiniApi::GetParmTagName = &FHoudiniApi::GetParmTagNameEmptyStub;

FHoudiniApi::GetParmTagValueFuncPtr FHoudiniApi::GetParmTagValue = &FHoudiniApi::GetParmTagValueEmptyStub;

FHoudiniApi::ParmHasTagFuncPtr FHoudiniApi::ParmHasTag = &FHoudiniApi::ParmHasTagEmptyStub;

FHoudiniApi::ParmHasExpressionFuncPtr FHoudiniApi::ParmHasExpression = &FHoudiniApi::ParmHasExpressionEmptyStub;

FHoudiniApi::GetParmWithTagFuncPtr FHoudiniApi::GetParmWithTag = &FHoudiniApi::GetParmWithTagEmptyStub;

FHoudiniApi::GetParmExpressionFuncPtr FHoudiniApi::GetParmExpression = &FHoudiniApi::GetParmExpressionEmptyStub;

FHoudiniApi::RevertParmToDefaultFuncPtr FHoudiniApi::RevertParmToDefault = &FHoudiniApi::RevertParmToDefaultEmptyStub;

FHoudiniApi::RevertParmToDefaultsFuncPtr FHoudiniApi::RevertParmToDefaults = &FHoudiniApi::RevertParmToDefaultsEmptyStub;

FHoudiniApi::SetParmExpressionFuncPtr FHoudiniApi::SetParmExpression = &FHoudiniApi::SetParmExpressionEmptyStub;

FHoudiniApi::GetParmIntValuesFuncPtr FHoudiniApi::GetParmIntValues = &FHoudiniApi::GetParmIntValuesEmptyStub;

FHoudiniApi::GetParmFloatValueFuncPtr FHoudiniApi::GetParmFloatValue = &FHoudiniApi::GetParmFloatValueEmptyStub;

FHoudiniApi::GetParmFloatValuesFuncPtr FHoudiniApi::GetParmFloatValues = &FHoudiniApi::GetParmFloatValuesEmptyStub;

FHoudiniApi::GetParmStringValueFuncPtr FHoudiniApi::GetParmStringValue = &FHoudiniApi::GetParmStringValueEmptyStub;

FHoudiniApi::GetParmStringValuesFuncPtr FHoudiniApi::GetParmStringValues = &FHoudiniApi::GetParmStringValuesEmptyStub;

FHoudiniApi::GetParmNodeValueFuncPtr FHoudiniApi::GetParmNodeValue = &FHoudiniApi::GetParmNodeValueEmptyStub;

FHoudiniApi::GetParmFileFuncPtr FHoudiniApi::GetParmFile = &FHoudiniApi::GetParmFileEmptyStub;

FHoudiniApi::GetParmChoiceListsFuncPtr FHoudiniApi::GetParmChoiceLists = &FHoudiniApi::GetParmChoiceListsEmptyStub;

FHoudiniApi::SetParmIntValueFuncPtr FHoudiniApi::SetParmIntValue = &FHoudiniApi::SetParmIntValueEmptyStub;

FHoudiniApi::SetParmIntValuesFuncPtr FHoudiniApi::SetParmIntValues = &FHoudiniApi::SetParmIntValuesEmptyStub;

FHoudiniApi::SetParmFloatValueFuncPtr FHoudiniApi::SetParmFloatValue = &FHoudiniApi::SetParmFloatValueEmptyStub;

FHoudiniApi::SetParmFloatValuesFuncPtr FHoudiniApi::SetParmFloatValues = &FHoudiniApi::SetParmFloatValuesEmptyStub;

FHoudiniApi::SetParmStringValueFuncPtr FHoudiniApi::SetParmStringValue = &FHoudiniApi::SetParmStringValueEmptyStub;

FHoudiniApi::SetParmNodeValueFuncPtr FHoudiniApi::SetParmNodeValue = &FHoudiniApi::SetParmNodeValueEmptyStub;

FHoudiniApi::InsertMultiparmInstanceFuncPtr FHoudiniApi::InsertMultiparmInstance = &FHoudiniApi::InsertMultiparmInstanceEmptyStub;

FHoudiniApi::RemoveMultiparmInstanceFuncPtr FHoudiniApi::RemoveMultiparmInstance = &FHoudiniApi::RemoveMultiparmInstanceEmptyStub;

FHoudiniApi::GetHandleInfoFuncPtr FHoudiniApi::GetHandleInfo = &FHoudiniApi::GetHandleInfoEmptyStub;

FHoudiniApi::GetHandleBindingInfoFuncPtr FHoudiniApi::GetHandleBindingInfo = &FHoudiniApi::GetHandleBindingInfoEmptyStub;

FHoudiniApi::GetPresetBufLengthFuncPtr FHoudiniApi::GetPresetBufLength = &FHoudiniApi::GetPresetBufLengthEmptyStub;

FHoudiniApi::GetPresetFuncPtr FHoudiniApi::GetPreset = &FHoudiniApi::GetPresetEmptyStub;

FHoudiniApi::SetPresetFuncPtr FHoudiniApi::SetPreset = &FHoudiniApi::SetPresetEmptyStub;

FHoudiniApi::GetObjectInfoFuncPtr FHoudiniApi::GetObjectInfo = &FHoudiniApi::GetObjectInfoEmptyStub;

FHoudiniApi::GetObjectTransformFuncPtr FHoudiniApi::GetObjectTransform = &FHoudiniApi::GetObjectTransformEmptyStub;

FHoudiniApi::ComposeObjectListFuncPtr FHoudiniApi::ComposeObjectList = &FHoudiniApi::ComposeObjectListEmptyStub;

FHoudiniApi::GetComposedObjectListFuncPtr FHoudiniApi::GetComposedObjectList = &FHoudiniApi::GetComposedObjectListEmptyStub;

FHoudiniApi::GetComposedObjectTransformsFuncPtr FHoudiniApi::GetComposedObjectTransforms = &FHoudiniApi::GetComposedObjectTransformsEmptyStub;

FHoudiniApi::GetInstancedObjectIdsFuncPtr FHoudiniApi::GetInstancedObjectIds = &FHoudiniApi::GetInstancedObjectIdsEmptyStub;

FHoudiniApi::GetInstanceTransformsFuncPtr FHoudiniApi::GetInstanceTransforms = &FHoudiniApi::GetInstanceTransformsEmptyStub;

FHoudiniApi::SetObjectTransformFuncPtr FHoudiniApi::SetObjectTransform = &FHoudiniApi::SetObjectTransformEmptyStub;

FHoudiniApi::GetDisplayGeoInfoFuncPtr FHoudiniApi::GetDisplayGeoInfo = &FHoudiniApi::GetDisplayGeoInfoEmptyStub;

FHoudiniApi::GetGeoInfoFuncPtr FHoudiniApi::GetGeoInfo = &FHoudiniApi::GetGeoInfoEmptyStub;

FHoudiniApi::GetPartInfoFuncPtr FHoudiniApi::GetPartInfo = &FHoudiniApi::GetPartInfoEmptyStub;

FHoudiniApi::GetFaceCountsFuncPtr FHoudiniApi::GetFaceCounts = &FHoudiniApi::GetFaceCountsEmptyStub;

FHoudiniApi::GetVertexListFuncPtr FHoudiniApi::GetVertexList = &FHoudiniApi::GetVertexListEmptyStub;

FHoudiniApi::GetAttributeInfoFuncPtr FHoudiniApi::GetAttributeInfo = &FHoudiniApi::GetAttributeInfoEmptyStub;

FHoudiniApi::GetAttributeNamesFuncPtr FHoudiniApi::GetAttributeNames = &FHoudiniApi::GetAttributeNamesEmptyStub;

FHoudiniApi::GetAttributeIntDataFuncPtr FHoudiniApi::GetAttributeIntData = &FHoudiniApi::GetAttributeIntDataEmptyStub;

FHoudiniApi::GetAttributeInt64DataFuncPtr FHoudiniApi::GetAttributeInt64Data = &FHoudiniApi::GetAttributeInt64DataEmptyStub;

FHoudiniApi::GetAttributeFloatDataFuncPtr FHoudiniApi::GetAttributeFloatData = &FHoudiniApi::GetAttributeFloatDataEmptyStub;

FHoudiniApi::GetAttributeFloat64DataFuncPtr FHoudiniApi::GetAttributeFloat64Data = &FHoudiniApi::GetAttributeFloat64DataEmptyStub;

FHoudiniApi::GetAttributeStringDataFuncPtr FHoudiniApi::GetAttributeStringData = &FHoudiniApi::GetAttributeStringDataEmptyStub;

FHoudiniApi::GetGroupNamesFuncPtr FHoudiniApi::GetGroupNames = &FHoudiniApi::GetGroupNamesEmptyStub;

FHoudiniApi::GetGroupMembershipFuncPtr FHoudiniApi::GetGroupMembership = &FHoudiniApi::GetGroupMembershipEmptyStub;

FHoudiniApi::GetGroupCountOnPackedInstancePartFuncPtr FHoudiniApi::GetGroupCountOnPackedInstancePart = &FHoudiniApi::GetGroupCountOnPackedInstancePartEmptyStub;

FHoudiniApi::GetGroupNamesOnPackedInstancePartFuncPtr FHoudiniApi::GetGroupNamesOnPackedInstancePart = &FHoudiniApi::GetGroupNamesOnPackedInstancePartEmptyStub;

FHoudiniApi::GetGroupMembershipOnPackedInstancePartFuncPtr FHoudiniApi::GetGroupMembershipOnPackedInstancePart = &FHoudiniApi::GetGroupMembershipOnPackedInstancePartEmptyStub;

FHoudiniApi::GetInstancedPartIdsFuncPtr FHoudiniApi::GetInstancedPartIds = &FHoudiniApi::GetInstancedPartIdsEmptyStub;

FHoudiniApi::GetInstancerPartTransformsFuncPtr FHoudiniApi::GetInstancerPartTransforms = &FHoudiniApi::GetInstancerPartTransformsEmptyStub;

FHoudiniApi::SetPartInfoFuncPtr FHoudiniApi::SetPartInfo = &FHoudiniApi::SetPartInfoEmptyStub;

FHoudiniApi::SetFaceCountsFuncPtr FHoudiniApi::SetFaceCounts = &FHoudiniApi::SetFaceCountsEmptyStub;

FHoudiniApi::SetVertexListFuncPtr FHoudiniApi::SetVertexList = &FHoudiniApi::SetVertexListEmptyStub;

FHoudiniApi::AddAttributeFuncPtr FHoudiniApi::AddAttribute = &FHoudiniApi::AddAttributeEmptyStub;

FHoudiniApi::SetAttributeIntDataFuncPtr FHoudiniApi::SetAttributeIntData = &FHoudiniApi::SetAttributeIntDataEmptyStub;

FHoudiniApi::SetAttributeInt64DataFuncPtr FHoudiniApi::SetAttributeInt64Data = &FHoudiniApi::SetAttributeInt64DataEmptyStub;

FHoudiniApi::SetAttributeFloatDataFuncPtr FHoudiniApi::SetAttributeFloatData = &FHoudiniApi::SetAttributeFloatDataEmptyStub;

FHoudiniApi::SetAttributeFloat64DataFuncPtr FHoudiniApi::SetAttributeFloat64Data = &FHoudiniApi::SetAttributeFloat64DataEmptyStub;

FHoudiniApi::SetAttributeStringDataFuncPtr FHoudiniApi::SetAttributeStringData = &FHoudiniApi::SetAttributeStringDataEmptyStub;

FHoudiniApi::AddGroupFuncPtr FHoudiniApi::AddGroup = &FHoudiniApi::AddGroupEmptyStub;

FHoudiniApi::SetGroupMembershipFuncPtr FHoudiniApi::SetGroupMembership = &FHoudiniApi::SetGroupMembershipEmptyStub;

FHoudiniApi::CommitGeoFuncPtr FHoudiniApi::CommitGeo = &FHoudiniApi::CommitGeoEmptyStub;

FHoudiniApi::RevertGeoFuncPtr FHoudiniApi::RevertGeo = &FHoudiniApi::RevertGeoEmptyStub;

FHoudiniApi::GetMaterialNodeIdsOnFacesFuncPtr FHoudiniApi::GetMaterialNodeIdsOnFaces = &FHoudiniApi::GetMaterialNodeIdsOnFacesEmptyStub;

FHoudiniApi::GetMaterialInfoFuncPtr FHoudiniApi::GetMaterialInfo = &FHoudiniApi::GetMaterialInfoEmptyStub;

FHoudiniApi::RenderCOPToImageFuncPtr FHoudiniApi::RenderCOPToImage = &FHoudiniApi::RenderCOPToImageEmptyStub;

FHoudiniApi::RenderTextureToImageFuncPtr FHoudiniApi::RenderTextureToImage = &FHoudiniApi::RenderTextureToImageEmptyStub;

FHoudiniApi::GetImageInfoFuncPtr FHoudiniApi::GetImageInfo = &FHoudiniApi::GetImageInfoEmptyStub;

FHoudiniApi::SetImageInfoFuncPtr FHoudiniApi::SetImageInfo = &FHoudiniApi::SetImageInfoEmptyStub;

FHoudiniApi::GetImagePlaneCountFuncPtr FHoudiniApi::GetImagePlaneCount = &FHoudiniApi::GetImagePlaneCountEmptyStub;

FHoudiniApi::GetImagePlanesFuncPtr FHoudiniApi::GetImagePlanes = &FHoudiniApi::GetImagePlanesEmptyStub;

FHoudiniApi::ExtractImageToFileFuncPtr FHoudiniApi::ExtractImageToFile = &FHoudiniApi::ExtractImageToFileEmptyStub;

FHoudiniApi::ExtractImageToMemoryFuncPtr FHoudiniApi::ExtractImageToMemory = &FHoudiniApi::ExtractImageToMemoryEmptyStub;

FHoudiniApi::GetImageMemoryBufferFuncPtr FHoudiniApi::GetImageMemoryBuffer = &FHoudiniApi::GetImageMemoryBufferEmptyStub;

FHoudiniApi::GetSupportedImageFileFormatCountFuncPtr FHoudiniApi::GetSupportedImageFileFormatCount = &FHoudiniApi::GetSupportedImageFileFormatCountEmptyStub;

FHoudiniApi::GetSupportedImageFileFormatsFuncPtr FHoudiniApi::GetSupportedImageFileFormats = &FHoudiniApi::GetSupportedImageFileFormatsEmptyStub;

FHoudiniApi::SetAnimCurveFuncPtr FHoudiniApi::SetAnimCurve = &FHoudiniApi::SetAnimCurveEmptyStub;

FHoudiniApi::SetTransformAnimCurveFuncPtr FHoudiniApi::SetTransformAnimCurve = &FHoudiniApi::SetTransformAnimCurveEmptyStub;

FHoudiniApi::ResetSimulationFuncPtr FHoudiniApi::ResetSimulation = &FHoudiniApi::ResetSimulationEmptyStub;

FHoudiniApi::GetVolumeInfoFuncPtr FHoudiniApi::GetVolumeInfo = &FHoudiniApi::GetVolumeInfoEmptyStub;

FHoudiniApi::GetFirstVolumeTileFuncPtr FHoudiniApi::GetFirstVolumeTile = &FHoudiniApi::GetFirstVolumeTileEmptyStub;

FHoudiniApi::GetNextVolumeTileFuncPtr FHoudiniApi::GetNextVolumeTile = &FHoudiniApi::GetNextVolumeTileEmptyStub;

FHoudiniApi::GetVolumeVoxelFloatDataFuncPtr FHoudiniApi::GetVolumeVoxelFloatData = &FHoudiniApi::GetVolumeVoxelFloatDataEmptyStub;

FHoudiniApi::GetVolumeTileFloatDataFuncPtr FHoudiniApi::GetVolumeTileFloatData = &FHoudiniApi::GetVolumeTileFloatDataEmptyStub;

FHoudiniApi::GetVolumeVoxelIntDataFuncPtr FHoudiniApi::GetVolumeVoxelIntData = &FHoudiniApi::GetVolumeVoxelIntDataEmptyStub;

FHoudiniApi::GetVolumeTileIntDataFuncPtr FHoudiniApi::GetVolumeTileIntData = &FHoudiniApi::GetVolumeTileIntDataEmptyStub;

FHoudiniApi::GetHeightFieldDataFuncPtr FHoudiniApi::GetHeightFieldData = &FHoudiniApi::GetHeightFieldDataEmptyStub;

FHoudiniApi::SetVolumeInfoFuncPtr FHoudiniApi::SetVolumeInfo = &FHoudiniApi::SetVolumeInfoEmptyStub;

FHoudiniApi::SetVolumeTileFloatDataFuncPtr FHoudiniApi::SetVolumeTileFloatData = &FHoudiniApi::SetVolumeTileFloatDataEmptyStub;

FHoudiniApi::SetVolumeTileIntDataFuncPtr FHoudiniApi::SetVolumeTileIntData = &FHoudiniApi::SetVolumeTileIntDataEmptyStub;

FHoudiniApi::SetVolumeVoxelFloatDataFuncPtr FHoudiniApi::SetVolumeVoxelFloatData = &FHoudiniApi::SetVolumeVoxelFloatDataEmptyStub;

FHoudiniApi::SetVolumeVoxelIntDataFuncPtr FHoudiniApi::SetVolumeVoxelIntData = &FHoudiniApi::SetVolumeVoxelIntDataEmptyStub;

FHoudiniApi::GetVolumeBoundsFuncPtr FHoudiniApi::GetVolumeBounds = &FHoudiniApi::GetVolumeBoundsEmptyStub;

FHoudiniApi::SetHeightFieldDataFuncPtr FHoudiniApi::SetHeightFieldData = &FHoudiniApi::SetHeightFieldDataEmptyStub;

FHoudiniApi::GetCurveInfoFuncPtr FHoudiniApi::GetCurveInfo = &FHoudiniApi::GetCurveInfoEmptyStub;

FHoudiniApi::GetCurveCountsFuncPtr FHoudiniApi::GetCurveCounts = &FHoudiniApi::GetCurveCountsEmptyStub;

FHoudiniApi::GetCurveOrdersFuncPtr FHoudiniApi::GetCurveOrders = &FHoudiniApi::GetCurveOrdersEmptyStub;

FHoudiniApi::GetCurveKnotsFuncPtr FHoudiniApi::GetCurveKnots = &FHoudiniApi::GetCurveKnotsEmptyStub;

FHoudiniApi::SetCurveInfoFuncPtr FHoudiniApi::SetCurveInfo = &FHoudiniApi::SetCurveInfoEmptyStub;

FHoudiniApi::SetCurveCountsFuncPtr FHoudiniApi::SetCurveCounts = &FHoudiniApi::SetCurveCountsEmptyStub;

FHoudiniApi::SetCurveOrdersFuncPtr FHoudiniApi::SetCurveOrders = &FHoudiniApi::SetCurveOrdersEmptyStub;

FHoudiniApi::SetCurveKnotsFuncPtr FHoudiniApi::SetCurveKnots = &FHoudiniApi::SetCurveKnotsEmptyStub;

FHoudiniApi::GetBoxInfoFuncPtr FHoudiniApi::GetBoxInfo = &FHoudiniApi::GetBoxInfoEmptyStub;

FHoudiniApi::GetSphereInfoFuncPtr FHoudiniApi::GetSphereInfo = &FHoudiniApi::GetSphereInfoEmptyStub;

FHoudiniApi::GetActiveCacheCountFuncPtr FHoudiniApi::GetActiveCacheCount = &FHoudiniApi::GetActiveCacheCountEmptyStub;

FHoudiniApi::GetActiveCacheNamesFuncPtr FHoudiniApi::GetActiveCacheNames = &FHoudiniApi::GetActiveCacheNamesEmptyStub;

FHoudiniApi::GetCachePropertyFuncPtr FHoudiniApi::GetCacheProperty = &FHoudiniApi::GetCachePropertyEmptyStub;

FHoudiniApi::SetCachePropertyFuncPtr FHoudiniApi::SetCacheProperty = &FHoudiniApi::SetCachePropertyEmptyStub;

FHoudiniApi::SaveGeoToFileFuncPtr FHoudiniApi::SaveGeoToFile = &FHoudiniApi::SaveGeoToFileEmptyStub;

FHoudiniApi::LoadGeoFromFileFuncPtr FHoudiniApi::LoadGeoFromFile = &FHoudiniApi::LoadGeoFromFileEmptyStub;

FHoudiniApi::GetGeoSizeFuncPtr FHoudiniApi::GetGeoSize = &FHoudiniApi::GetGeoSizeEmptyStub;

FHoudiniApi::SaveGeoToMemoryFuncPtr FHoudiniApi::SaveGeoToMemory = &FHoudiniApi::SaveGeoToMemoryEmptyStub;

FHoudiniApi::LoadGeoFromMemoryFuncPtr FHoudiniApi::LoadGeoFromMemory = &FHoudiniApi::LoadGeoFromMemoryEmptyStub;

void FHoudiniApi::Bind(void* Handle)
{
    ensure(Handle);

  FHoudiniApi::CreateInProcessSession = (CreateInProcessSessionFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_CreateInProcessSession"));
  FHoudiniApi::StartThriftSocketServer = (StartThriftSocketServerFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_StartThriftSocketServer"));
  FHoudiniApi::CreateThriftSocketSession = (CreateThriftSocketSessionFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_CreateThriftSocketSession"));
  FHoudiniApi::StartThriftNamedPipeServer = (StartThriftNamedPipeServerFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_StartThriftNamedPipeServer"));
  FHoudiniApi::CreateThriftNamedPipeSession = (CreateThriftNamedPipeSessionFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_CreateThriftNamedPipeSession"));
  FHoudiniApi::BindCustomImplementation = (BindCustomImplementationFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_BindCustomImplementation"));
  FHoudiniApi::CreateCustomSession = (CreateCustomSessionFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_CreateCustomSession"));
  FHoudiniApi::IsSessionValid = (IsSessionValidFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_IsSessionValid"));
  FHoudiniApi::CloseSession = (CloseSessionFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_CloseSession"));
  FHoudiniApi::IsInitialized = (IsInitializedFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_IsInitialized"));
  FHoudiniApi::Initialize = (InitializeFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_Initialize"));
  FHoudiniApi::Cleanup = (CleanupFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_Cleanup"));
  FHoudiniApi::GetEnvInt = (GetEnvIntFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetEnvInt"));
  FHoudiniApi::GetSessionEnvInt = (GetSessionEnvIntFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetSessionEnvInt"));
  FHoudiniApi::GetServerEnvInt = (GetServerEnvIntFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetServerEnvInt"));
  FHoudiniApi::GetServerEnvString = (GetServerEnvStringFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetServerEnvString"));
  FHoudiniApi::SetServerEnvInt = (SetServerEnvIntFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_SetServerEnvInt"));
  FHoudiniApi::SetServerEnvString = (SetServerEnvStringFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_SetServerEnvString"));
  FHoudiniApi::GetStatus = (GetStatusFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetStatus"));
  FHoudiniApi::GetStatusStringBufLength = (GetStatusStringBufLengthFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetStatusStringBufLength"));
  FHoudiniApi::GetStatusString = (GetStatusStringFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetStatusString"));
  FHoudiniApi::ComposeNodeCookResult = (ComposeNodeCookResultFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_ComposeNodeCookResult"));
  FHoudiniApi::GetComposedNodeCookResult = (GetComposedNodeCookResultFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetComposedNodeCookResult"));
  FHoudiniApi::CheckForSpecificErrors = (CheckForSpecificErrorsFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_CheckForSpecificErrors"));
  FHoudiniApi::GetCookingTotalCount = (GetCookingTotalCountFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetCookingTotalCount"));
  FHoudiniApi::GetCookingCurrentCount = (GetCookingCurrentCountFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetCookingCurrentCount"));
  FHoudiniApi::ConvertTransform = (ConvertTransformFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_ConvertTransform"));
  FHoudiniApi::ConvertMatrixToQuat = (ConvertMatrixToQuatFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_ConvertMatrixToQuat"));
  FHoudiniApi::ConvertMatrixToEuler = (ConvertMatrixToEulerFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_ConvertMatrixToEuler"));
  FHoudiniApi::ConvertTransformQuatToMatrix = (ConvertTransformQuatToMatrixFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_ConvertTransformQuatToMatrix"));
  FHoudiniApi::ConvertTransformEulerToMatrix = (ConvertTransformEulerToMatrixFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_ConvertTransformEulerToMatrix"));
  FHoudiniApi::PythonThreadInterpreterLock = (PythonThreadInterpreterLockFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_PythonThreadInterpreterLock"));
  FHoudiniApi::GetStringBufLength = (GetStringBufLengthFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetStringBufLength"));
  FHoudiniApi::GetString = (GetStringFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetString"));
  FHoudiniApi::GetStringBatchSize = (GetStringBatchSizeFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetStringBatchSize"));
  FHoudiniApi::GetStringBatch = (GetStringBatchFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetStringBatch"));
  FHoudiniApi::GetTime = (GetTimeFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetTime"));
  FHoudiniApi::SetTime = (SetTimeFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_SetTime"));
  FHoudiniApi::GetTimelineOptions = (GetTimelineOptionsFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetTimelineOptions"));
  FHoudiniApi::SetTimelineOptions = (SetTimelineOptionsFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_SetTimelineOptions"));
  FHoudiniApi::LoadAssetLibraryFromFile = (LoadAssetLibraryFromFileFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_LoadAssetLibraryFromFile"));
  FHoudiniApi::LoadAssetLibraryFromMemory = (LoadAssetLibraryFromMemoryFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_LoadAssetLibraryFromMemory"));
  FHoudiniApi::GetAvailableAssetCount = (GetAvailableAssetCountFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetAvailableAssetCount"));
  FHoudiniApi::GetAvailableAssets = (GetAvailableAssetsFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetAvailableAssets"));
  FHoudiniApi::GetAssetInfo = (GetAssetInfoFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetAssetInfo"));
  FHoudiniApi::Interrupt = (InterruptFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_Interrupt"));
  FHoudiniApi::LoadHIPFile = (LoadHIPFileFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_LoadHIPFile"));
  FHoudiniApi::SaveHIPFile = (SaveHIPFileFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_SaveHIPFile"));
  FHoudiniApi::IsNodeValid = (IsNodeValidFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_IsNodeValid"));
  FHoudiniApi::GetNodeInfo = (GetNodeInfoFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetNodeInfo"));
  FHoudiniApi::GetNodePath = (GetNodePathFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetNodePath"));
  FHoudiniApi::GetManagerNodeId = (GetManagerNodeIdFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetManagerNodeId"));
  FHoudiniApi::ComposeChildNodeList = (ComposeChildNodeListFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_ComposeChildNodeList"));
  FHoudiniApi::GetComposedChildNodeList = (GetComposedChildNodeListFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetComposedChildNodeList"));
  FHoudiniApi::CreateNode = (CreateNodeFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_CreateNode"));
  FHoudiniApi::CreateInputNode = (CreateInputNodeFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_CreateInputNode"));
  FHoudiniApi::CookNode = (CookNodeFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_CookNode"));
  FHoudiniApi::DeleteNode = (DeleteNodeFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_DeleteNode"));
  FHoudiniApi::RenameNode = (RenameNodeFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_RenameNode"));
  FHoudiniApi::ConnectNodeInput = (ConnectNodeInputFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_ConnectNodeInput"));
  FHoudiniApi::DisconnectNodeInput = (DisconnectNodeInputFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_DisconnectNodeInput"));
  FHoudiniApi::QueryNodeInput = (QueryNodeInputFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_QueryNodeInput"));
  FHoudiniApi::GetNodeInputName = (GetNodeInputNameFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetNodeInputName"));
  FHoudiniApi::DisconnectNodeOutputsAt = (DisconnectNodeOutputsAtFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_DisconnectNodeOutputsAt"));
  FHoudiniApi::QueryNodeOutputConnectedCount = (QueryNodeOutputConnectedCountFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_QueryNodeOutputConnectedCount"));
  FHoudiniApi::QueryNodeOutputConnectedNodes = (QueryNodeOutputConnectedNodesFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_QueryNodeOutputConnectedNodes"));
  FHoudiniApi::GetNodeOutputName = (GetNodeOutputNameFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetNodeOutputName"));
  FHoudiniApi::GetParameters = (GetParametersFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetParameters"));
  FHoudiniApi::GetParmInfo = (GetParmInfoFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetParmInfo"));
  FHoudiniApi::GetParmIdFromName = (GetParmIdFromNameFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetParmIdFromName"));
  FHoudiniApi::GetParmInfoFromName = (GetParmInfoFromNameFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetParmInfoFromName"));
  FHoudiniApi::GetParmTagName = (GetParmTagNameFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetParmTagName"));
  FHoudiniApi::GetParmTagValue = (GetParmTagValueFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetParmTagValue"));
  FHoudiniApi::ParmHasTag = (ParmHasTagFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_ParmHasTag"));
  FHoudiniApi::ParmHasExpression = (ParmHasExpressionFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_ParmHasExpression"));
  FHoudiniApi::GetParmWithTag = (GetParmWithTagFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetParmWithTag"));
  FHoudiniApi::GetParmExpression = (GetParmExpressionFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetParmExpression"));
  FHoudiniApi::RevertParmToDefault = (RevertParmToDefaultFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_RevertParmToDefault"));
  FHoudiniApi::RevertParmToDefaults = (RevertParmToDefaultsFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_RevertParmToDefaults"));
  FHoudiniApi::SetParmExpression = (SetParmExpressionFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_SetParmExpression"));
  FHoudiniApi::GetParmIntValues = (GetParmIntValuesFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetParmIntValues"));
  FHoudiniApi::GetParmFloatValue = (GetParmFloatValueFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetParmFloatValue"));
  FHoudiniApi::GetParmFloatValues = (GetParmFloatValuesFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetParmFloatValues"));
  FHoudiniApi::GetParmStringValue = (GetParmStringValueFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetParmStringValue"));
  FHoudiniApi::GetParmStringValues = (GetParmStringValuesFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetParmStringValues"));
  FHoudiniApi::GetParmNodeValue = (GetParmNodeValueFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetParmNodeValue"));
  FHoudiniApi::GetParmFile = (GetParmFileFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetParmFile"));
  FHoudiniApi::GetParmChoiceLists = (GetParmChoiceListsFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetParmChoiceLists"));
  FHoudiniApi::SetParmIntValue = (SetParmIntValueFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_SetParmIntValue"));
  FHoudiniApi::SetParmIntValues = (SetParmIntValuesFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_SetParmIntValues"));
  FHoudiniApi::SetParmFloatValue = (SetParmFloatValueFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_SetParmFloatValue"));
  FHoudiniApi::SetParmFloatValues = (SetParmFloatValuesFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_SetParmFloatValues"));
  FHoudiniApi::SetParmStringValue = (SetParmStringValueFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_SetParmStringValue"));
  FHoudiniApi::SetParmNodeValue = (SetParmNodeValueFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_SetParmNodeValue"));
  FHoudiniApi::InsertMultiparmInstance = (InsertMultiparmInstanceFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_InsertMultiparmInstance"));
  FHoudiniApi::RemoveMultiparmInstance = (RemoveMultiparmInstanceFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_RemoveMultiparmInstance"));
  FHoudiniApi::GetHandleInfo = (GetHandleInfoFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetHandleInfo"));
  FHoudiniApi::GetHandleBindingInfo = (GetHandleBindingInfoFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetHandleBindingInfo"));
  FHoudiniApi::GetPresetBufLength = (GetPresetBufLengthFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetPresetBufLength"));
  FHoudiniApi::GetPreset = (GetPresetFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetPreset"));
  FHoudiniApi::SetPreset = (SetPresetFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_SetPreset"));
  FHoudiniApi::GetObjectInfo = (GetObjectInfoFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetObjectInfo"));
  FHoudiniApi::GetObjectTransform = (GetObjectTransformFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetObjectTransform"));
  FHoudiniApi::ComposeObjectList = (ComposeObjectListFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_ComposeObjectList"));
  FHoudiniApi::GetComposedObjectList = (GetComposedObjectListFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetComposedObjectList"));
  FHoudiniApi::GetComposedObjectTransforms = (GetComposedObjectTransformsFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetComposedObjectTransforms"));
  FHoudiniApi::GetInstancedObjectIds = (GetInstancedObjectIdsFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetInstancedObjectIds"));
  FHoudiniApi::GetInstanceTransforms = (GetInstanceTransformsFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetInstanceTransforms"));
  FHoudiniApi::SetObjectTransform = (SetObjectTransformFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_SetObjectTransform"));
  FHoudiniApi::GetDisplayGeoInfo = (GetDisplayGeoInfoFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetDisplayGeoInfo"));
  FHoudiniApi::GetGeoInfo = (GetGeoInfoFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetGeoInfo"));
  FHoudiniApi::GetPartInfo = (GetPartInfoFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetPartInfo"));
  FHoudiniApi::GetFaceCounts = (GetFaceCountsFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetFaceCounts"));
  FHoudiniApi::GetVertexList = (GetVertexListFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetVertexList"));
  FHoudiniApi::GetAttributeInfo = (GetAttributeInfoFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetAttributeInfo"));
  FHoudiniApi::GetAttributeNames = (GetAttributeNamesFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetAttributeNames"));
  FHoudiniApi::GetAttributeIntData = (GetAttributeIntDataFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetAttributeIntData"));
  FHoudiniApi::GetAttributeInt64Data = (GetAttributeInt64DataFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetAttributeInt64Data"));
  FHoudiniApi::GetAttributeFloatData = (GetAttributeFloatDataFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetAttributeFloatData"));
  FHoudiniApi::GetAttributeFloat64Data = (GetAttributeFloat64DataFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetAttributeFloat64Data"));
  FHoudiniApi::GetAttributeStringData = (GetAttributeStringDataFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetAttributeStringData"));
  FHoudiniApi::GetGroupNames = (GetGroupNamesFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetGroupNames"));
  FHoudiniApi::GetGroupMembership = (GetGroupMembershipFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetGroupMembership"));
  FHoudiniApi::GetGroupCountOnPackedInstancePart = (GetGroupCountOnPackedInstancePartFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetGroupCountOnPackedInstancePart"));
  FHoudiniApi::GetGroupNamesOnPackedInstancePart = (GetGroupNamesOnPackedInstancePartFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetGroupNamesOnPackedInstancePart"));
  FHoudiniApi::GetGroupMembershipOnPackedInstancePart = (GetGroupMembershipOnPackedInstancePartFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetGroupMembershipOnPackedInstancePart"));
  FHoudiniApi::GetInstancedPartIds = (GetInstancedPartIdsFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetInstancedPartIds"));
  FHoudiniApi::GetInstancerPartTransforms = (GetInstancerPartTransformsFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetInstancerPartTransforms"));
  FHoudiniApi::SetPartInfo = (SetPartInfoFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_SetPartInfo"));
  FHoudiniApi::SetFaceCounts = (SetFaceCountsFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_SetFaceCounts"));
  FHoudiniApi::SetVertexList = (SetVertexListFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_SetVertexList"));
  FHoudiniApi::AddAttribute = (AddAttributeFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_AddAttribute"));
  FHoudiniApi::SetAttributeIntData = (SetAttributeIntDataFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_SetAttributeIntData"));
  FHoudiniApi::SetAttributeInt64Data = (SetAttributeInt64DataFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_SetAttributeInt64Data"));
  FHoudiniApi::SetAttributeFloatData = (SetAttributeFloatDataFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_SetAttributeFloatData"));
  FHoudiniApi::SetAttributeFloat64Data = (SetAttributeFloat64DataFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_SetAttributeFloat64Data"));
  FHoudiniApi::SetAttributeStringData = (SetAttributeStringDataFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_SetAttributeStringData"));
  FHoudiniApi::AddGroup = (AddGroupFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_AddGroup"));
  FHoudiniApi::SetGroupMembership = (SetGroupMembershipFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_SetGroupMembership"));
  FHoudiniApi::CommitGeo = (CommitGeoFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_CommitGeo"));
  FHoudiniApi::RevertGeo = (RevertGeoFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_RevertGeo"));
  FHoudiniApi::GetMaterialNodeIdsOnFaces = (GetMaterialNodeIdsOnFacesFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetMaterialNodeIdsOnFaces"));
  FHoudiniApi::GetMaterialInfo = (GetMaterialInfoFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetMaterialInfo"));
  FHoudiniApi::RenderCOPToImage = (RenderCOPToImageFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_RenderCOPToImage"));
  FHoudiniApi::RenderTextureToImage = (RenderTextureToImageFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_RenderTextureToImage"));
  FHoudiniApi::GetImageInfo = (GetImageInfoFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetImageInfo"));
  FHoudiniApi::SetImageInfo = (SetImageInfoFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_SetImageInfo"));
  FHoudiniApi::GetImagePlaneCount = (GetImagePlaneCountFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetImagePlaneCount"));
  FHoudiniApi::GetImagePlanes = (GetImagePlanesFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetImagePlanes"));
  FHoudiniApi::ExtractImageToFile = (ExtractImageToFileFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_ExtractImageToFile"));
  FHoudiniApi::ExtractImageToMemory = (ExtractImageToMemoryFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_ExtractImageToMemory"));
  FHoudiniApi::GetImageMemoryBuffer = (GetImageMemoryBufferFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetImageMemoryBuffer"));
  FHoudiniApi::GetSupportedImageFileFormatCount = (GetSupportedImageFileFormatCountFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetSupportedImageFileFormatCount"));
  FHoudiniApi::GetSupportedImageFileFormats = (GetSupportedImageFileFormatsFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetSupportedImageFileFormats"));
  FHoudiniApi::SetAnimCurve = (SetAnimCurveFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_SetAnimCurve"));
  FHoudiniApi::SetTransformAnimCurve = (SetTransformAnimCurveFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_SetTransformAnimCurve"));
  FHoudiniApi::ResetSimulation = (ResetSimulationFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_ResetSimulation"));
  FHoudiniApi::GetVolumeInfo = (GetVolumeInfoFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetVolumeInfo"));
  FHoudiniApi::GetFirstVolumeTile = (GetFirstVolumeTileFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetFirstVolumeTile"));
  FHoudiniApi::GetNextVolumeTile = (GetNextVolumeTileFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetNextVolumeTile"));
  FHoudiniApi::GetVolumeVoxelFloatData = (GetVolumeVoxelFloatDataFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetVolumeVoxelFloatData"));
  FHoudiniApi::GetVolumeTileFloatData = (GetVolumeTileFloatDataFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetVolumeTileFloatData"));
  FHoudiniApi::GetVolumeVoxelIntData = (GetVolumeVoxelIntDataFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetVolumeVoxelIntData"));
  FHoudiniApi::GetVolumeTileIntData = (GetVolumeTileIntDataFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetVolumeTileIntData"));
  FHoudiniApi::GetHeightFieldData = (GetHeightFieldDataFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetHeightFieldData"));
  FHoudiniApi::SetVolumeInfo = (SetVolumeInfoFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_SetVolumeInfo"));
  FHoudiniApi::SetVolumeTileFloatData = (SetVolumeTileFloatDataFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_SetVolumeTileFloatData"));
  FHoudiniApi::SetVolumeTileIntData = (SetVolumeTileIntDataFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_SetVolumeTileIntData"));
  FHoudiniApi::SetVolumeVoxelFloatData = (SetVolumeVoxelFloatDataFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_SetVolumeVoxelFloatData"));
  FHoudiniApi::SetVolumeVoxelIntData = (SetVolumeVoxelIntDataFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_SetVolumeVoxelIntData"));
  FHoudiniApi::GetVolumeBounds = (GetVolumeBoundsFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetVolumeBounds"));
  FHoudiniApi::SetHeightFieldData = (SetHeightFieldDataFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_SetHeightFieldData"));
  FHoudiniApi::GetCurveInfo = (GetCurveInfoFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetCurveInfo"));
  FHoudiniApi::GetCurveCounts = (GetCurveCountsFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetCurveCounts"));
  FHoudiniApi::GetCurveOrders = (GetCurveOrdersFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetCurveOrders"));
  FHoudiniApi::GetCurveKnots = (GetCurveKnotsFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetCurveKnots"));
  FHoudiniApi::SetCurveInfo = (SetCurveInfoFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_SetCurveInfo"));
  FHoudiniApi::SetCurveCounts = (SetCurveCountsFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_SetCurveCounts"));
  FHoudiniApi::SetCurveOrders = (SetCurveOrdersFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_SetCurveOrders"));
  FHoudiniApi::SetCurveKnots = (SetCurveKnotsFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_SetCurveKnots"));
  FHoudiniApi::GetBoxInfo = (GetBoxInfoFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetBoxInfo"));
  FHoudiniApi::GetSphereInfo = (GetSphereInfoFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetSphereInfo"));
  FHoudiniApi::GetActiveCacheCount = (GetActiveCacheCountFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetActiveCacheCount"));
  FHoudiniApi::GetActiveCacheNames = (GetActiveCacheNamesFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetActiveCacheNames"));
  FHoudiniApi::GetCacheProperty = (GetCachePropertyFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetCacheProperty"));
  FHoudiniApi::SetCacheProperty = (SetCachePropertyFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_SetCacheProperty"));
  FHoudiniApi::SaveGeoToFile = (SaveGeoToFileFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_SaveGeoToFile"));
  FHoudiniApi::LoadGeoFromFile = (LoadGeoFromFileFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_LoadGeoFromFile"));
  FHoudiniApi::GetGeoSize = (GetGeoSizeFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_GetGeoSize"));
  FHoudiniApi::SaveGeoToMemory = (SaveGeoToMemoryFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_SaveGeoToMemory"));
  FHoudiniApi::LoadGeoFromMemory = (LoadGeoFromMemoryFuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT("HAPI_LoadGeoFromMemory"));
}

void FHoudiniApi::Unbind()
{
  FHoudiniApi::CreateInProcessSession = &FHoudiniApi::CreateInProcessSessionEmptyStub;
  FHoudiniApi::StartThriftSocketServer = &FHoudiniApi::StartThriftSocketServerEmptyStub;
  FHoudiniApi::CreateThriftSocketSession = &FHoudiniApi::CreateThriftSocketSessionEmptyStub;
  FHoudiniApi::StartThriftNamedPipeServer = &FHoudiniApi::StartThriftNamedPipeServerEmptyStub;
  FHoudiniApi::CreateThriftNamedPipeSession = &FHoudiniApi::CreateThriftNamedPipeSessionEmptyStub;
  FHoudiniApi::BindCustomImplementation = &FHoudiniApi::BindCustomImplementationEmptyStub;
  FHoudiniApi::CreateCustomSession = &FHoudiniApi::CreateCustomSessionEmptyStub;
  FHoudiniApi::IsSessionValid = &FHoudiniApi::IsSessionValidEmptyStub;
  FHoudiniApi::CloseSession = &FHoudiniApi::CloseSessionEmptyStub;
  FHoudiniApi::IsInitialized = &FHoudiniApi::IsInitializedEmptyStub;
  FHoudiniApi::Initialize = &FHoudiniApi::InitializeEmptyStub;
  FHoudiniApi::Cleanup = &FHoudiniApi::CleanupEmptyStub;
  FHoudiniApi::GetEnvInt = &FHoudiniApi::GetEnvIntEmptyStub;
  FHoudiniApi::GetSessionEnvInt = &FHoudiniApi::GetSessionEnvIntEmptyStub;
  FHoudiniApi::GetServerEnvInt = &FHoudiniApi::GetServerEnvIntEmptyStub;
  FHoudiniApi::GetServerEnvString = &FHoudiniApi::GetServerEnvStringEmptyStub;
  FHoudiniApi::SetServerEnvInt = &FHoudiniApi::SetServerEnvIntEmptyStub;
  FHoudiniApi::SetServerEnvString = &FHoudiniApi::SetServerEnvStringEmptyStub;
  FHoudiniApi::GetStatus = &FHoudiniApi::GetStatusEmptyStub;
  FHoudiniApi::GetStatusStringBufLength = &FHoudiniApi::GetStatusStringBufLengthEmptyStub;
  FHoudiniApi::GetStatusString = &FHoudiniApi::GetStatusStringEmptyStub;
  FHoudiniApi::ComposeNodeCookResult = &FHoudiniApi::ComposeNodeCookResultEmptyStub;
  FHoudiniApi::GetComposedNodeCookResult = &FHoudiniApi::GetComposedNodeCookResultEmptyStub;
  FHoudiniApi::CheckForSpecificErrors = &FHoudiniApi::CheckForSpecificErrorsEmptyStub;
  FHoudiniApi::GetCookingTotalCount = &FHoudiniApi::GetCookingTotalCountEmptyStub;
  FHoudiniApi::GetCookingCurrentCount = &FHoudiniApi::GetCookingCurrentCountEmptyStub;
  FHoudiniApi::ConvertTransform = &FHoudiniApi::ConvertTransformEmptyStub;
  FHoudiniApi::ConvertMatrixToQuat = &FHoudiniApi::ConvertMatrixToQuatEmptyStub;
  FHoudiniApi::ConvertMatrixToEuler = &FHoudiniApi::ConvertMatrixToEulerEmptyStub;
  FHoudiniApi::ConvertTransformQuatToMatrix = &FHoudiniApi::ConvertTransformQuatToMatrixEmptyStub;
  FHoudiniApi::ConvertTransformEulerToMatrix = &FHoudiniApi::ConvertTransformEulerToMatrixEmptyStub;
  FHoudiniApi::PythonThreadInterpreterLock = &FHoudiniApi::PythonThreadInterpreterLockEmptyStub;
  FHoudiniApi::GetStringBufLength = &FHoudiniApi::GetStringBufLengthEmptyStub;
  FHoudiniApi::GetString = &FHoudiniApi::GetStringEmptyStub;
  FHoudiniApi::GetStringBatchSize = &FHoudiniApi::GetStringBatchSizeEmptyStub;
  FHoudiniApi::GetStringBatch = &FHoudiniApi::GetStringBatchEmptyStub;
  FHoudiniApi::GetTime = &FHoudiniApi::GetTimeEmptyStub;
  FHoudiniApi::SetTime = &FHoudiniApi::SetTimeEmptyStub;
  FHoudiniApi::GetTimelineOptions = &FHoudiniApi::GetTimelineOptionsEmptyStub;
  FHoudiniApi::SetTimelineOptions = &FHoudiniApi::SetTimelineOptionsEmptyStub;
  FHoudiniApi::LoadAssetLibraryFromFile = &FHoudiniApi::LoadAssetLibraryFromFileEmptyStub;
  FHoudiniApi::LoadAssetLibraryFromMemory = &FHoudiniApi::LoadAssetLibraryFromMemoryEmptyStub;
  FHoudiniApi::GetAvailableAssetCount = &FHoudiniApi::GetAvailableAssetCountEmptyStub;
  FHoudiniApi::GetAvailableAssets = &FHoudiniApi::GetAvailableAssetsEmptyStub;
  FHoudiniApi::GetAssetInfo = &FHoudiniApi::GetAssetInfoEmptyStub;
  FHoudiniApi::Interrupt = &FHoudiniApi::InterruptEmptyStub;
  FHoudiniApi::LoadHIPFile = &FHoudiniApi::LoadHIPFileEmptyStub;
  FHoudiniApi::SaveHIPFile = &FHoudiniApi::SaveHIPFileEmptyStub;
  FHoudiniApi::IsNodeValid = &FHoudiniApi::IsNodeValidEmptyStub;
  FHoudiniApi::GetNodeInfo = &FHoudiniApi::GetNodeInfoEmptyStub;
  FHoudiniApi::GetNodePath = &FHoudiniApi::GetNodePathEmptyStub;
  FHoudiniApi::GetManagerNodeId = &FHoudiniApi::GetManagerNodeIdEmptyStub;
  FHoudiniApi::ComposeChildNodeList = &FHoudiniApi::ComposeChildNodeListEmptyStub;
  FHoudiniApi::GetComposedChildNodeList = &FHoudiniApi::GetComposedChildNodeListEmptyStub;
  FHoudiniApi::CreateNode = &FHoudiniApi::CreateNodeEmptyStub;
  FHoudiniApi::CreateInputNode = &FHoudiniApi::CreateInputNodeEmptyStub;
  FHoudiniApi::CookNode = &FHoudiniApi::CookNodeEmptyStub;
  FHoudiniApi::DeleteNode = &FHoudiniApi::DeleteNodeEmptyStub;
  FHoudiniApi::RenameNode = &FHoudiniApi::RenameNodeEmptyStub;
  FHoudiniApi::ConnectNodeInput = &FHoudiniApi::ConnectNodeInputEmptyStub;
  FHoudiniApi::DisconnectNodeInput = &FHoudiniApi::DisconnectNodeInputEmptyStub;
  FHoudiniApi::QueryNodeInput = &FHoudiniApi::QueryNodeInputEmptyStub;
  FHoudiniApi::GetNodeInputName = &FHoudiniApi::GetNodeInputNameEmptyStub;
  FHoudiniApi::DisconnectNodeOutputsAt = &FHoudiniApi::DisconnectNodeOutputsAtEmptyStub;
  FHoudiniApi::QueryNodeOutputConnectedCount = &FHoudiniApi::QueryNodeOutputConnectedCountEmptyStub;
  FHoudiniApi::QueryNodeOutputConnectedNodes = &FHoudiniApi::QueryNodeOutputConnectedNodesEmptyStub;
  FHoudiniApi::GetNodeOutputName = &FHoudiniApi::GetNodeOutputNameEmptyStub;
  FHoudiniApi::GetParameters = &FHoudiniApi::GetParametersEmptyStub;
  FHoudiniApi::GetParmInfo = &FHoudiniApi::GetParmInfoEmptyStub;
  FHoudiniApi::GetParmIdFromName = &FHoudiniApi::GetParmIdFromNameEmptyStub;
  FHoudiniApi::GetParmInfoFromName = &FHoudiniApi::GetParmInfoFromNameEmptyStub;
  FHoudiniApi::GetParmTagName = &FHoudiniApi::GetParmTagNameEmptyStub;
  FHoudiniApi::GetParmTagValue = &FHoudiniApi::GetParmTagValueEmptyStub;
  FHoudiniApi::ParmHasTag = &FHoudiniApi::ParmHasTagEmptyStub;
  FHoudiniApi::ParmHasExpression = &FHoudiniApi::ParmHasExpressionEmptyStub;
  FHoudiniApi::GetParmWithTag = &FHoudiniApi::GetParmWithTagEmptyStub;
  FHoudiniApi::GetParmExpression = &FHoudiniApi::GetParmExpressionEmptyStub;
  FHoudiniApi::RevertParmToDefault = &FHoudiniApi::RevertParmToDefaultEmptyStub;
  FHoudiniApi::RevertParmToDefaults = &FHoudiniApi::RevertParmToDefaultsEmptyStub;
  FHoudiniApi::SetParmExpression = &FHoudiniApi::SetParmExpressionEmptyStub;
  FHoudiniApi::GetParmIntValues = &FHoudiniApi::GetParmIntValuesEmptyStub;
  FHoudiniApi::GetParmFloatValue = &FHoudiniApi::GetParmFloatValueEmptyStub;
  FHoudiniApi::GetParmFloatValues = &FHoudiniApi::GetParmFloatValuesEmptyStub;
  FHoudiniApi::GetParmStringValue = &FHoudiniApi::GetParmStringValueEmptyStub;
  FHoudiniApi::GetParmStringValues = &FHoudiniApi::GetParmStringValuesEmptyStub;
  FHoudiniApi::GetParmNodeValue = &FHoudiniApi::GetParmNodeValueEmptyStub;
  FHoudiniApi::GetParmFile = &FHoudiniApi::GetParmFileEmptyStub;
  FHoudiniApi::GetParmChoiceLists = &FHoudiniApi::GetParmChoiceListsEmptyStub;
  FHoudiniApi::SetParmIntValue = &FHoudiniApi::SetParmIntValueEmptyStub;
  FHoudiniApi::SetParmIntValues = &FHoudiniApi::SetParmIntValuesEmptyStub;
  FHoudiniApi::SetParmFloatValue = &FHoudiniApi::SetParmFloatValueEmptyStub;
  FHoudiniApi::SetParmFloatValues = &FHoudiniApi::SetParmFloatValuesEmptyStub;
  FHoudiniApi::SetParmStringValue = &FHoudiniApi::SetParmStringValueEmptyStub;
  FHoudiniApi::SetParmNodeValue = &FHoudiniApi::SetParmNodeValueEmptyStub;
  FHoudiniApi::InsertMultiparmInstance = &FHoudiniApi::InsertMultiparmInstanceEmptyStub;
  FHoudiniApi::RemoveMultiparmInstance = &FHoudiniApi::RemoveMultiparmInstanceEmptyStub;
  FHoudiniApi::GetHandleInfo = &FHoudiniApi::GetHandleInfoEmptyStub;
  FHoudiniApi::GetHandleBindingInfo = &FHoudiniApi::GetHandleBindingInfoEmptyStub;
  FHoudiniApi::GetPresetBufLength = &FHoudiniApi::GetPresetBufLengthEmptyStub;
  FHoudiniApi::GetPreset = &FHoudiniApi::GetPresetEmptyStub;
  FHoudiniApi::SetPreset = &FHoudiniApi::SetPresetEmptyStub;
  FHoudiniApi::GetObjectInfo = &FHoudiniApi::GetObjectInfoEmptyStub;
  FHoudiniApi::GetObjectTransform = &FHoudiniApi::GetObjectTransformEmptyStub;
  FHoudiniApi::ComposeObjectList = &FHoudiniApi::ComposeObjectListEmptyStub;
  FHoudiniApi::GetComposedObjectList = &FHoudiniApi::GetComposedObjectListEmptyStub;
  FHoudiniApi::GetComposedObjectTransforms = &FHoudiniApi::GetComposedObjectTransformsEmptyStub;
  FHoudiniApi::GetInstancedObjectIds = &FHoudiniApi::GetInstancedObjectIdsEmptyStub;
  FHoudiniApi::GetInstanceTransforms = &FHoudiniApi::GetInstanceTransformsEmptyStub;
  FHoudiniApi::SetObjectTransform = &FHoudiniApi::SetObjectTransformEmptyStub;
  FHoudiniApi::GetDisplayGeoInfo = &FHoudiniApi::GetDisplayGeoInfoEmptyStub;
  FHoudiniApi::GetGeoInfo = &FHoudiniApi::GetGeoInfoEmptyStub;
  FHoudiniApi::GetPartInfo = &FHoudiniApi::GetPartInfoEmptyStub;
  FHoudiniApi::GetFaceCounts = &FHoudiniApi::GetFaceCountsEmptyStub;
  FHoudiniApi::GetVertexList = &FHoudiniApi::GetVertexListEmptyStub;
  FHoudiniApi::GetAttributeInfo = &FHoudiniApi::GetAttributeInfoEmptyStub;
  FHoudiniApi::GetAttributeNames = &FHoudiniApi::GetAttributeNamesEmptyStub;
  FHoudiniApi::GetAttributeIntData = &FHoudiniApi::GetAttributeIntDataEmptyStub;
  FHoudiniApi::GetAttributeInt64Data = &FHoudiniApi::GetAttributeInt64DataEmptyStub;
  FHoudiniApi::GetAttributeFloatData = &FHoudiniApi::GetAttributeFloatDataEmptyStub;
  FHoudiniApi::GetAttributeFloat64Data = &FHoudiniApi::GetAttributeFloat64DataEmptyStub;
  FHoudiniApi::GetAttributeStringData = &FHoudiniApi::GetAttributeStringDataEmptyStub;
  FHoudiniApi::GetGroupNames = &FHoudiniApi::GetGroupNamesEmptyStub;
  FHoudiniApi::GetGroupMembership = &FHoudiniApi::GetGroupMembershipEmptyStub;
  FHoudiniApi::GetGroupCountOnPackedInstancePart = &FHoudiniApi::GetGroupCountOnPackedInstancePartEmptyStub;
  FHoudiniApi::GetGroupNamesOnPackedInstancePart = &FHoudiniApi::GetGroupNamesOnPackedInstancePartEmptyStub;
  FHoudiniApi::GetGroupMembershipOnPackedInstancePart = &FHoudiniApi::GetGroupMembershipOnPackedInstancePartEmptyStub;
  FHoudiniApi::GetInstancedPartIds = &FHoudiniApi::GetInstancedPartIdsEmptyStub;
  FHoudiniApi::GetInstancerPartTransforms = &FHoudiniApi::GetInstancerPartTransformsEmptyStub;
  FHoudiniApi::SetPartInfo = &FHoudiniApi::SetPartInfoEmptyStub;
  FHoudiniApi::SetFaceCounts = &FHoudiniApi::SetFaceCountsEmptyStub;
  FHoudiniApi::SetVertexList = &FHoudiniApi::SetVertexListEmptyStub;
  FHoudiniApi::AddAttribute = &FHoudiniApi::AddAttributeEmptyStub;
  FHoudiniApi::SetAttributeIntData = &FHoudiniApi::SetAttributeIntDataEmptyStub;
  FHoudiniApi::SetAttributeInt64Data = &FHoudiniApi::SetAttributeInt64DataEmptyStub;
  FHoudiniApi::SetAttributeFloatData = &FHoudiniApi::SetAttributeFloatDataEmptyStub;
  FHoudiniApi::SetAttributeFloat64Data = &FHoudiniApi::SetAttributeFloat64DataEmptyStub;
  FHoudiniApi::SetAttributeStringData = &FHoudiniApi::SetAttributeStringDataEmptyStub;
  FHoudiniApi::AddGroup = &FHoudiniApi::AddGroupEmptyStub;
  FHoudiniApi::SetGroupMembership = &FHoudiniApi::SetGroupMembershipEmptyStub;
  FHoudiniApi::CommitGeo = &FHoudiniApi::CommitGeoEmptyStub;
  FHoudiniApi::RevertGeo = &FHoudiniApi::RevertGeoEmptyStub;
  FHoudiniApi::GetMaterialNodeIdsOnFaces = &FHoudiniApi::GetMaterialNodeIdsOnFacesEmptyStub;
  FHoudiniApi::GetMaterialInfo = &FHoudiniApi::GetMaterialInfoEmptyStub;
  FHoudiniApi::RenderCOPToImage = &FHoudiniApi::RenderCOPToImageEmptyStub;
  FHoudiniApi::RenderTextureToImage = &FHoudiniApi::RenderTextureToImageEmptyStub;
  FHoudiniApi::GetImageInfo = &FHoudiniApi::GetImageInfoEmptyStub;
  FHoudiniApi::SetImageInfo = &FHoudiniApi::SetImageInfoEmptyStub;
  FHoudiniApi::GetImagePlaneCount = &FHoudiniApi::GetImagePlaneCountEmptyStub;
  FHoudiniApi::GetImagePlanes = &FHoudiniApi::GetImagePlanesEmptyStub;
  FHoudiniApi::ExtractImageToFile = &FHoudiniApi::ExtractImageToFileEmptyStub;
  FHoudiniApi::ExtractImageToMemory = &FHoudiniApi::ExtractImageToMemoryEmptyStub;
  FHoudiniApi::GetImageMemoryBuffer = &FHoudiniApi::GetImageMemoryBufferEmptyStub;
  FHoudiniApi::GetSupportedImageFileFormatCount = &FHoudiniApi::GetSupportedImageFileFormatCountEmptyStub;
  FHoudiniApi::GetSupportedImageFileFormats = &FHoudiniApi::GetSupportedImageFileFormatsEmptyStub;
  FHoudiniApi::SetAnimCurve = &FHoudiniApi::SetAnimCurveEmptyStub;
  FHoudiniApi::SetTransformAnimCurve = &FHoudiniApi::SetTransformAnimCurveEmptyStub;
  FHoudiniApi::ResetSimulation = &FHoudiniApi::ResetSimulationEmptyStub;
  FHoudiniApi::GetVolumeInfo = &FHoudiniApi::GetVolumeInfoEmptyStub;
  FHoudiniApi::GetFirstVolumeTile = &FHoudiniApi::GetFirstVolumeTileEmptyStub;
  FHoudiniApi::GetNextVolumeTile = &FHoudiniApi::GetNextVolumeTileEmptyStub;
  FHoudiniApi::GetVolumeVoxelFloatData = &FHoudiniApi::GetVolumeVoxelFloatDataEmptyStub;
  FHoudiniApi::GetVolumeTileFloatData = &FHoudiniApi::GetVolumeTileFloatDataEmptyStub;
  FHoudiniApi::GetVolumeVoxelIntData = &FHoudiniApi::GetVolumeVoxelIntDataEmptyStub;
  FHoudiniApi::GetVolumeTileIntData = &FHoudiniApi::GetVolumeTileIntDataEmptyStub;
  FHoudiniApi::GetHeightFieldData = &FHoudiniApi::GetHeightFieldDataEmptyStub;
  FHoudiniApi::SetVolumeInfo = &FHoudiniApi::SetVolumeInfoEmptyStub;
  FHoudiniApi::SetVolumeTileFloatData = &FHoudiniApi::SetVolumeTileFloatDataEmptyStub;
  FHoudiniApi::SetVolumeTileIntData = &FHoudiniApi::SetVolumeTileIntDataEmptyStub;
  FHoudiniApi::SetVolumeVoxelFloatData = &FHoudiniApi::SetVolumeVoxelFloatDataEmptyStub;
  FHoudiniApi::SetVolumeVoxelIntData = &FHoudiniApi::SetVolumeVoxelIntDataEmptyStub;
  FHoudiniApi::GetVolumeBounds = &FHoudiniApi::GetVolumeBoundsEmptyStub;
  FHoudiniApi::SetHeightFieldData = &FHoudiniApi::SetHeightFieldDataEmptyStub;
  FHoudiniApi::GetCurveInfo = &FHoudiniApi::GetCurveInfoEmptyStub;
  FHoudiniApi::GetCurveCounts = &FHoudiniApi::GetCurveCountsEmptyStub;
  FHoudiniApi::GetCurveOrders = &FHoudiniApi::GetCurveOrdersEmptyStub;
  FHoudiniApi::GetCurveKnots = &FHoudiniApi::GetCurveKnotsEmptyStub;
  FHoudiniApi::SetCurveInfo = &FHoudiniApi::SetCurveInfoEmptyStub;
  FHoudiniApi::SetCurveCounts = &FHoudiniApi::SetCurveCountsEmptyStub;
  FHoudiniApi::SetCurveOrders = &FHoudiniApi::SetCurveOrdersEmptyStub;
  FHoudiniApi::SetCurveKnots = &FHoudiniApi::SetCurveKnotsEmptyStub;
  FHoudiniApi::GetBoxInfo = &FHoudiniApi::GetBoxInfoEmptyStub;
  FHoudiniApi::GetSphereInfo = &FHoudiniApi::GetSphereInfoEmptyStub;
  FHoudiniApi::GetActiveCacheCount = &FHoudiniApi::GetActiveCacheCountEmptyStub;
  FHoudiniApi::GetActiveCacheNames = &FHoudiniApi::GetActiveCacheNamesEmptyStub;
  FHoudiniApi::GetCacheProperty = &FHoudiniApi::GetCachePropertyEmptyStub;
  FHoudiniApi::SetCacheProperty = &FHoudiniApi::SetCachePropertyEmptyStub;
  FHoudiniApi::SaveGeoToFile = &FHoudiniApi::SaveGeoToFileEmptyStub;
  FHoudiniApi::LoadGeoFromFile = &FHoudiniApi::LoadGeoFromFileEmptyStub;
  FHoudiniApi::GetGeoSize = &FHoudiniApi::GetGeoSizeEmptyStub;
  FHoudiniApi::SaveGeoToMemory = &FHoudiniApi::SaveGeoToMemoryEmptyStub;
  FHoudiniApi::LoadGeoFromMemory = &FHoudiniApi::LoadGeoFromMemoryEmptyStub;
}

HAPI_Result FHoudiniApi::CreateInProcessSessionEmptyStub(HAPI_Session * session)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::StartThriftSocketServerEmptyStub(const HAPI_ThriftServerOptions * options, int port, HAPI_ProcessId * process_id)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::CreateThriftSocketSessionEmptyStub(HAPI_Session * session, const char * host_name, int port)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::StartThriftNamedPipeServerEmptyStub(const HAPI_ThriftServerOptions * options, const char * pipe_name, HAPI_ProcessId * process_id)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::CreateThriftNamedPipeSessionEmptyStub(HAPI_Session * session, const char * pipe_name)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::BindCustomImplementationEmptyStub(HAPI_SessionType session_type, const char * dll_path)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::CreateCustomSessionEmptyStub(HAPI_SessionType session_type, void * session_info, HAPI_Session * session)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::IsSessionValidEmptyStub(const HAPI_Session * session)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::CloseSessionEmptyStub(const HAPI_Session * session)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::IsInitializedEmptyStub(const HAPI_Session * session)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::InitializeEmptyStub(const HAPI_Session * session, const HAPI_CookOptions * cook_options, HAPI_Bool use_cooking_thread, int cooking_thread_stack_size, const char * houdini_environment_files, const char * otl_search_path, const char * dso_search_path, const char * image_dso_search_path, const char * audio_dso_search_path)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::CleanupEmptyStub(const HAPI_Session * session)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetEnvIntEmptyStub(HAPI_EnvIntType int_type, int * value)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetSessionEnvIntEmptyStub(const HAPI_Session * session, HAPI_SessionEnvIntType int_type, int * value)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetServerEnvIntEmptyStub(const HAPI_Session * session, const char * variable_name, int * value)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetServerEnvStringEmptyStub(const HAPI_Session * session, const char * variable_name, HAPI_StringHandle * value)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::SetServerEnvIntEmptyStub(const HAPI_Session * session, const char * variable_name, int value)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::SetServerEnvStringEmptyStub(const HAPI_Session * session, const char * variable_name, const char * value)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetStatusEmptyStub(const HAPI_Session * session, HAPI_StatusType status_type, int * status)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetStatusStringBufLengthEmptyStub(const HAPI_Session * session, HAPI_StatusType status_type, HAPI_StatusVerbosity verbosity, int * buffer_length)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetStatusStringEmptyStub(const HAPI_Session * session, HAPI_StatusType status_type, char * string_value, int length)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::ComposeNodeCookResultEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, HAPI_StatusVerbosity verbosity, int * buffer_length)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetComposedNodeCookResultEmptyStub(const HAPI_Session * session, char * string_value, int length)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::CheckForSpecificErrorsEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, HAPI_ErrorCodeBits errors_to_look_for, HAPI_ErrorCodeBits * errors_found)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetCookingTotalCountEmptyStub(const HAPI_Session * session, int * count)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetCookingCurrentCountEmptyStub(const HAPI_Session * session, int * count)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::ConvertTransformEmptyStub(const HAPI_Session * session, const HAPI_TransformEuler * transform_in, HAPI_RSTOrder rst_order, HAPI_XYZOrder rot_order, HAPI_TransformEuler * transform_out)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::ConvertMatrixToQuatEmptyStub(const HAPI_Session * session, const float * matrix, HAPI_RSTOrder rst_order, HAPI_Transform * transform_out)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::ConvertMatrixToEulerEmptyStub(const HAPI_Session * session, const float * matrix, HAPI_RSTOrder rst_order, HAPI_XYZOrder rot_order, HAPI_TransformEuler * transform_out)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::ConvertTransformQuatToMatrixEmptyStub(const HAPI_Session * session, const HAPI_Transform * transform, float * matrix)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::ConvertTransformEulerToMatrixEmptyStub(const HAPI_Session * session, const HAPI_TransformEuler * transform, float * matrix)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::PythonThreadInterpreterLockEmptyStub(const HAPI_Session * session, HAPI_Bool locked)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetStringBufLengthEmptyStub(const HAPI_Session * session, HAPI_StringHandle string_handle, int * buffer_length)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetStringEmptyStub(const HAPI_Session * session, HAPI_StringHandle string_handle, char * string_value, int length)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetStringBatchSizeEmptyStub(const HAPI_Session * session, const int * string_handle_array, int string_handle_count, int* string_buffer_size)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetStringBatchEmptyStub(const HAPI_Session * session, char * char_array, int char_array_length)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetTimeEmptyStub(const HAPI_Session * session, float * time)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::SetTimeEmptyStub(const HAPI_Session * session, float time)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetTimelineOptionsEmptyStub(const HAPI_Session * session, HAPI_TimelineOptions * timeline_options)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::SetTimelineOptionsEmptyStub(const HAPI_Session * session, const HAPI_TimelineOptions * timeline_options)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::LoadAssetLibraryFromFileEmptyStub(const HAPI_Session * session, const char * file_path, HAPI_Bool allow_overwrite, HAPI_AssetLibraryId* library_id)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::LoadAssetLibraryFromMemoryEmptyStub(const HAPI_Session * session, const char * library_buffer, int library_buffer_length, HAPI_Bool allow_overwrite, HAPI_AssetLibraryId * library_id)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetAvailableAssetCountEmptyStub(const HAPI_Session * session, HAPI_AssetLibraryId library_id, int * asset_count)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetAvailableAssetsEmptyStub(const HAPI_Session * session, HAPI_AssetLibraryId library_id, HAPI_StringHandle * asset_names_array, int asset_count)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetAssetInfoEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, HAPI_AssetInfo * asset_info)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::InterruptEmptyStub(const HAPI_Session * session)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::LoadHIPFileEmptyStub(const HAPI_Session * session, const char * file_name, HAPI_Bool cook_on_load)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::SaveHIPFileEmptyStub(const HAPI_Session * session, const char * file_path, HAPI_Bool lock_nodes)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::IsNodeValidEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, int unique_node_id, HAPI_Bool * answer)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetNodeInfoEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, HAPI_NodeInfo * node_info)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetNodePathEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, HAPI_NodeId relative_to_node_id, HAPI_StringHandle * path)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetManagerNodeIdEmptyStub(const HAPI_Session * session, HAPI_NodeType node_type, HAPI_NodeId * node_id)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::ComposeChildNodeListEmptyStub(const HAPI_Session * session, HAPI_NodeId parent_node_id, HAPI_NodeTypeBits node_type_filter, HAPI_NodeFlagsBits node_flags_filter, HAPI_Bool recursive, int * count)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetComposedChildNodeListEmptyStub(const HAPI_Session * session, HAPI_NodeId parent_node_id, HAPI_NodeId * child_node_ids_array, int count)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::CreateNodeEmptyStub(const HAPI_Session * session, HAPI_NodeId parent_node_id, const char * operator_name, const char * node_label, HAPI_Bool cook_on_creation, HAPI_NodeId * new_node_id)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::CreateInputNodeEmptyStub(const HAPI_Session * session, HAPI_NodeId * node_id, const char * name)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::CookNodeEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, const HAPI_CookOptions * cook_options)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::DeleteNodeEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::RenameNodeEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, const char * new_name)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::ConnectNodeInputEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, int input_index, HAPI_NodeId node_id_to_connect, int output_index)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::DisconnectNodeInputEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, int input_index)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::QueryNodeInputEmptyStub(const HAPI_Session * session, HAPI_NodeId node_to_query, int input_index, HAPI_NodeId * connected_node_id)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetNodeInputNameEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, int input_idx, HAPI_StringHandle * name)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::DisconnectNodeOutputsAtEmptyStub(const HAPI_Session *session, HAPI_NodeId node_id, int output_index)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::QueryNodeOutputConnectedCountEmptyStub(const HAPI_Session *session, HAPI_NodeId node_id, int output_idx, HAPI_Bool into_subnets, HAPI_Bool through_dots, int * connected_count)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::QueryNodeOutputConnectedNodesEmptyStub(const HAPI_Session *session, HAPI_NodeId node_id, int output_idx, HAPI_Bool into_subnets, HAPI_Bool through_dots, HAPI_NodeId * connected_node_ids, int start, int length)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetNodeOutputNameEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, int output_idx, HAPI_StringHandle * name)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetParametersEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, HAPI_ParmInfo * parm_infos_array, int start, int length)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetParmInfoEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, HAPI_ParmId parm_id, HAPI_ParmInfo * parm_info)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetParmIdFromNameEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, const char * parm_name, HAPI_ParmId * parm_id)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetParmInfoFromNameEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, const char * parm_name, HAPI_ParmInfo * parm_info)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetParmTagNameEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, HAPI_ParmId parm_id, int tag_index, HAPI_StringHandle * tag_name)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetParmTagValueEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, HAPI_ParmId parm_id, const char * tag_name, HAPI_StringHandle * tag_value)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::ParmHasTagEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, HAPI_ParmId parm_id, const char * tag_name, HAPI_Bool * has_tag)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::ParmHasExpressionEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, const char * parm_name, int index, HAPI_Bool * has_expression)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetParmWithTagEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, const char * tag_name, HAPI_ParmId * parm_id)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetParmExpressionEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, const char * parm_name, int index, HAPI_StringHandle * value)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::RevertParmToDefaultEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, const char * parm_name, int index)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::RevertParmToDefaultsEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, const char * parm_name)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::SetParmExpressionEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, const char * value, HAPI_ParmId parm_id, int index)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetParmIntValuesEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, int * values_array, int start, int length)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetParmFloatValueEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, const char * parm_name, int index, float * value)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetParmFloatValuesEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, float * values_array, int start, int length)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetParmStringValueEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, const char * parm_name, int index, HAPI_Bool evaluate, HAPI_StringHandle * value)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetParmStringValuesEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, HAPI_Bool evaluate, HAPI_StringHandle * values_array, int start, int length)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetParmNodeValueEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, const char * parm_name, HAPI_NodeId * value)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetParmFileEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, const char * parm_name, const char * destination_directory, const char * destination_file_name)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetParmChoiceListsEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, HAPI_ParmChoiceInfo *parm_choices_array, int start, int length)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::SetParmIntValueEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, const char * parm_name, int index, int value)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::SetParmIntValuesEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, const int * values_array, int start, int length)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::SetParmFloatValueEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, const char * parm_name, int index, float value)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::SetParmFloatValuesEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, const float * values_array, int start, int length)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::SetParmStringValueEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, const char * value, HAPI_ParmId parm_id, int index)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::SetParmNodeValueEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, const char * parm_name, HAPI_NodeId value)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::InsertMultiparmInstanceEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, HAPI_ParmId parm_id, int instance_position)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::RemoveMultiparmInstanceEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, HAPI_ParmId parm_id, int instance_position)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetHandleInfoEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, HAPI_HandleInfo * handle_infos_array, int start, int length)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetHandleBindingInfoEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, int handle_index, HAPI_HandleBindingInfo * handle_binding_infos_array, int start, int length)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetPresetBufLengthEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, HAPI_PresetType preset_type, const char * preset_name, int * buffer_length)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetPresetEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, char * buffer, int buffer_length)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::SetPresetEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, HAPI_PresetType preset_type, const char * preset_name, const char * buffer, int buffer_length)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetObjectInfoEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, HAPI_ObjectInfo * object_info)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetObjectTransformEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, HAPI_NodeId relative_to_node_id, HAPI_RSTOrder rst_order, HAPI_Transform * transform)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::ComposeObjectListEmptyStub(const HAPI_Session * session, HAPI_NodeId parent_node_id, const char * categories, int * object_count)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetComposedObjectListEmptyStub(const HAPI_Session * session, HAPI_NodeId parent_node_id, HAPI_ObjectInfo * object_infos_array, int start, int length)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetComposedObjectTransformsEmptyStub(const HAPI_Session * session, HAPI_NodeId parent_node_id, HAPI_RSTOrder rst_order, HAPI_Transform * transform_array, int start, int length)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetInstancedObjectIdsEmptyStub(const HAPI_Session * session, HAPI_NodeId object_node_id, HAPI_NodeId * instanced_node_id_array, int start, int length)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetInstanceTransformsEmptyStub(const HAPI_Session * session, HAPI_NodeId object_node_id, HAPI_RSTOrder rst_order, HAPI_Transform * transforms_array, int start, int length)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::SetObjectTransformEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, const HAPI_TransformEuler * trans)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetDisplayGeoInfoEmptyStub(const HAPI_Session * session, HAPI_NodeId object_node_id, HAPI_GeoInfo * geo_info)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetGeoInfoEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, HAPI_GeoInfo * geo_info)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetPartInfoEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, HAPI_PartId part_id, HAPI_PartInfo * part_info)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetFaceCountsEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, HAPI_PartId part_id, int * face_counts_array, int start, int length)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetVertexListEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, HAPI_PartId part_id, int * vertex_list_array, int start, int length)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetAttributeInfoEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, HAPI_PartId part_id, const char * name, HAPI_AttributeOwner owner, HAPI_AttributeInfo * attr_info)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetAttributeNamesEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, HAPI_PartId part_id, HAPI_AttributeOwner owner, HAPI_StringHandle * attribute_names_array, int count)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetAttributeIntDataEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, HAPI_PartId part_id, const char * name, HAPI_AttributeInfo * attr_info, int stride, int * data_array, int start, int length)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetAttributeInt64DataEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, HAPI_PartId part_id, const char * name, HAPI_AttributeInfo * attr_info, int stride, HAPI_Int64 * data_array, int start, int length)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetAttributeFloatDataEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, HAPI_PartId part_id, const char * name, HAPI_AttributeInfo * attr_info, int stride, float * data_array, int start, int length)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetAttributeFloat64DataEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, HAPI_PartId part_id, const char * name, HAPI_AttributeInfo * attr_info, int stride, double * data_array, int start, int length)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetAttributeStringDataEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, HAPI_PartId part_id, const char * name, HAPI_AttributeInfo * attr_info, HAPI_StringHandle * data_array, int start, int length)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetGroupNamesEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, HAPI_GroupType group_type, HAPI_StringHandle * group_names_array, int group_count)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetGroupMembershipEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, HAPI_PartId part_id, HAPI_GroupType group_type, const char * group_name, HAPI_Bool * membership_array_all_equal, int * membership_array, int start, int length)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetGroupCountOnPackedInstancePartEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, HAPI_PartId part_id, int * pointGroupCount, int * primitiveGroupCount)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetGroupNamesOnPackedInstancePartEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, HAPI_PartId part_id, HAPI_GroupType group_type, HAPI_StringHandle * group_names_array, int group_count)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetGroupMembershipOnPackedInstancePartEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, HAPI_PartId part_id, HAPI_GroupType group_type, const char * group_name, HAPI_Bool * membership_array_all_equal, int * membership_array, int start, int length)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetInstancedPartIdsEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, HAPI_PartId part_id, HAPI_PartId * instanced_parts_array, int start, int length)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetInstancerPartTransformsEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, HAPI_PartId part_id, HAPI_RSTOrder rst_order, HAPI_Transform * transforms_array, int start, int length)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::SetPartInfoEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, HAPI_PartId part_id, const HAPI_PartInfo * part_info)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::SetFaceCountsEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, HAPI_PartId part_id, const int * face_counts_array, int start, int length)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::SetVertexListEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, HAPI_PartId part_id, const int * vertex_list_array, int start, int length)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::AddAttributeEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, HAPI_PartId part_id, const char * name, const HAPI_AttributeInfo * attr_info)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::SetAttributeIntDataEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, HAPI_PartId part_id, const char * name, const HAPI_AttributeInfo * attr_info, const int * data_array, int start, int length)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::SetAttributeInt64DataEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, HAPI_PartId part_id, const char * name, const HAPI_AttributeInfo * attr_info, const HAPI_Int64 * data_array, int start, int length)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::SetAttributeFloatDataEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, HAPI_PartId part_id, const char * name, const HAPI_AttributeInfo * attr_info, const float * data_array, int start, int length)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::SetAttributeFloat64DataEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, HAPI_PartId part_id, const char * name, const HAPI_AttributeInfo * attr_info, const double * data_array, int start, int length)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::SetAttributeStringDataEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, HAPI_PartId part_id, const char * name, const HAPI_AttributeInfo *attr_info, const char ** data_array, int start, int length)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::AddGroupEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, HAPI_PartId part_id, HAPI_GroupType group_type, const char * group_name)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::SetGroupMembershipEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, HAPI_PartId part_id, HAPI_GroupType group_type, const char * group_name, const int * membership_array, int start, int length)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::CommitGeoEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::RevertGeoEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetMaterialNodeIdsOnFacesEmptyStub(const HAPI_Session * session, HAPI_NodeId geometry_node_id, HAPI_PartId part_id, HAPI_Bool * are_all_the_same, HAPI_NodeId * material_ids_array, int start, int length)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetMaterialInfoEmptyStub(const HAPI_Session * session, HAPI_NodeId material_node_id, HAPI_MaterialInfo * material_info)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::RenderCOPToImageEmptyStub(const HAPI_Session * session, HAPI_NodeId cop_node_id)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::RenderTextureToImageEmptyStub(const HAPI_Session * session, HAPI_NodeId material_node_id, HAPI_ParmId parm_id)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetImageInfoEmptyStub(const HAPI_Session * session, HAPI_NodeId material_node_id, HAPI_ImageInfo * image_info)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::SetImageInfoEmptyStub(const HAPI_Session * session, HAPI_NodeId material_node_id, const HAPI_ImageInfo * image_info)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetImagePlaneCountEmptyStub(const HAPI_Session * session, HAPI_NodeId material_node_id, int * image_plane_count)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetImagePlanesEmptyStub(const HAPI_Session * session, HAPI_NodeId material_node_id, HAPI_StringHandle * image_planes_array, int image_plane_count)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::ExtractImageToFileEmptyStub(const HAPI_Session * session, HAPI_NodeId material_node_id, const char * image_file_format_name, const char * image_planes, const char * destination_folder_path, const char * destination_file_name, int * destination_file_path)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::ExtractImageToMemoryEmptyStub(const HAPI_Session * session, HAPI_NodeId material_node_id, const char * image_file_format_name, const char * image_planes, int * buffer_size)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetImageMemoryBufferEmptyStub(const HAPI_Session * session, HAPI_NodeId material_node_id, char * buffer, int length)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetSupportedImageFileFormatCountEmptyStub(const HAPI_Session * session, int * file_format_count)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetSupportedImageFileFormatsEmptyStub(const HAPI_Session * session, HAPI_ImageFileFormat * formats_array, int file_format_count)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::SetAnimCurveEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, HAPI_ParmId parm_id, int parm_index, const HAPI_Keyframe * curve_keyframes_array, int keyframe_count)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::SetTransformAnimCurveEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, HAPI_TransformComponent trans_comp, const HAPI_Keyframe * curve_keyframes_array, int keyframe_count)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::ResetSimulationEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetVolumeInfoEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, HAPI_PartId part_id, HAPI_VolumeInfo * volume_info)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetFirstVolumeTileEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, HAPI_PartId part_id, HAPI_VolumeTileInfo * tile)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetNextVolumeTileEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, HAPI_PartId part_id, HAPI_VolumeTileInfo * tile)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetVolumeVoxelFloatDataEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, HAPI_PartId part_id, int x_index, int y_index, int z_index, float * values_array, int value_count)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetVolumeTileFloatDataEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, HAPI_PartId part_id, float fill_value, const HAPI_VolumeTileInfo * tile, float * values_array, int length)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetVolumeVoxelIntDataEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, HAPI_PartId part_id, int x_index, int y_index, int z_index, int * values_array, int value_count)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetVolumeTileIntDataEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, HAPI_PartId part_id, int fill_value, const HAPI_VolumeTileInfo * tile, int * values_array, int length)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetHeightFieldDataEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, HAPI_PartId part_id, float * values_array, int start, int length)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::SetVolumeInfoEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, HAPI_PartId part_id, const HAPI_VolumeInfo * volume_info)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::SetVolumeTileFloatDataEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, HAPI_PartId part_id, const HAPI_VolumeTileInfo * tile, const float * values_array, int length)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::SetVolumeTileIntDataEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, HAPI_PartId part_id, const HAPI_VolumeTileInfo * tile, const int * values_array, int length)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::SetVolumeVoxelFloatDataEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, HAPI_PartId part_id, int x_index, int y_index, int z_index, const float * values_array, int value_count)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::SetVolumeVoxelIntDataEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, HAPI_PartId part_id, int x_index, int y_index, int z_index, const int * values_array, int value_count)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetVolumeBoundsEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, HAPI_PartId part_id, float * x_min, float * y_min, float * z_min, float * x_max, float * y_max, float * z_max, float * x_center, float * y_center, float * z_center)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::SetHeightFieldDataEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, HAPI_PartId part_id, const char * name, const float * values_array, int start, int length)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetCurveInfoEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, HAPI_PartId part_id, HAPI_CurveInfo * info)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetCurveCountsEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, HAPI_PartId part_id, int * counts_array, int start, int length)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetCurveOrdersEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, HAPI_PartId part_id, int * orders_array, int start, int length)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetCurveKnotsEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, HAPI_PartId part_id, float * knots_array, int start, int length)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::SetCurveInfoEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, HAPI_PartId part_id, const HAPI_CurveInfo * info)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::SetCurveCountsEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, HAPI_PartId part_id, const int * counts_array, int start, int length)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::SetCurveOrdersEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, HAPI_PartId part_id, const int * orders_array, int start, int length)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::SetCurveKnotsEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, HAPI_PartId part_id, const float * knots_array, int start, int length)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetBoxInfoEmptyStub(const HAPI_Session * session, HAPI_NodeId geo_node_id, HAPI_PartId part_id, HAPI_BoxInfo * box_info)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetSphereInfoEmptyStub(const HAPI_Session * session, HAPI_NodeId geo_node_id, HAPI_PartId part_id, HAPI_SphereInfo * sphere_info)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetActiveCacheCountEmptyStub(const HAPI_Session * session, int * active_cache_count)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetActiveCacheNamesEmptyStub(const HAPI_Session * session, HAPI_StringHandle * cache_names_array, int active_cache_count)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetCachePropertyEmptyStub(const HAPI_Session * session, const char * cache_name, HAPI_CacheProperty cache_property, int * property_value)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::SetCachePropertyEmptyStub(const HAPI_Session * session, const char * cache_name, HAPI_CacheProperty cache_property, int property_value)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::SaveGeoToFileEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, const char * file_name)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::LoadGeoFromFileEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, const char * file_name)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::GetGeoSizeEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, const char * format, int * size)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::SaveGeoToMemoryEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, char * buffer, int length)
{
    return HAPI_RESULT_FAILURE;
}

HAPI_Result FHoudiniApi::LoadGeoFromMemoryEmptyStub(const HAPI_Session * session, HAPI_NodeId node_id, const char * format, const char * buffer, int length)
{
    return HAPI_RESULT_FAILURE;
}

