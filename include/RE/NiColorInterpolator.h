#pragma once

#include "RE/NiColors.h"  // NiColorA
#include "RE/NiKeyBasedInterpolator.h"  // NiKeyBasedInterpolator
#include "RE/NiSmartPointer.h"  // NiPointer


namespace RE
{
	class NiColorData;


	class NiColorInterpolator : public NiKeyBasedInterpolator
	{
	public:
		virtual ~NiColorInterpolator();																		// 00

		// override (NiKeyBasedInterpolator)
		virtual NiRTTI*			GetRTTI() override;															// 02
		virtual NiObject*		CreateClone(NiCloningProcess a_cloner) override;							// 17
		virtual void			LoadBinary(NiStream* a_stream) override;									// 18
		virtual bool			RegisterStreamables(NiStream* a_stream) override;							// 1A
		virtual void			SaveBinary(NiStream* a_stream) override;									// 1B
		virtual bool			IsEqual(NiObject* a_object) override;										// 1C
		virtual bool			Update(float a_delta, NiObjectNET* a_target, NiColorA* a_data) override;	// 26
		virtual bool			IsColorAValueSupported() const override;									// 2F - { return true; }
		virtual void			Collapse() override;														// 31
		virtual void			GuaranteeTimeRange(float a_start, float a_end) override;					// 33
		virtual NiInterpolator*	GetSequenceInterpolator(float a_start, float a_end) override;				// 34
		virtual UInt16			GetKeyChannelCount() const override;										// 39 - { return 1; }
		virtual UInt32			GetKeyCount(UInt16 a_channel) const override;								// 3A - { return data ? data->count : 0; }
		virtual UInt32			GetKeyContent(UInt16 a_channel) const override;								// 3B - { return data ? data->content : 0; }
		virtual KeyType			GetKeyType(UInt16 a_channel) const override;								// 3C - { return 3; }
		virtual void*			GetKeyArray(UInt16 a_channel) const override;								// 3D - { return data ? data->arr : 0; }
		virtual UInt8			GetKeyStride(UInt16 a_channel) const override;								// 3E - { return data ? data->stride : 0; }
		virtual bool			GetChannelPosed(UInt16 a_channel) const override;							// 3F


		// members
		NiColorA				value;		// 18
		NiPointer<NiColorData>	data;		// 28
		UInt32					lastIndex;	// 30
		UInt32					unk34;		// 34
	};
	STATIC_ASSERT(sizeof(NiColorInterpolator) == 0x38);
}