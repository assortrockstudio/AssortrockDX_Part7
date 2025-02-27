#pragma once

#define SINGLE(Type)	private:\
							Type();\
					 		Type(const Type& _origin) = delete;\
						public:\
					 		~Type();\
					 	friend class CSingleton<Type>;

#define DEVICE CDevice::GetInst()->GetDevice()
#define CONTEXT CDevice::GetInst()->GetContext()

#define KEY_CHECK(Key, State) (CKeyMgr::GetInst()->GetKeyState(Key) == State)
#define KEY_TAP(Key)		KEY_CHECK(Key, KEY_STATE::TAP)
#define KEY_PRESSED(Key)	KEY_CHECK(Key, KEY_STATE::PRESSED)
#define KEY_RELEASED(Key)	KEY_CHECK(Key, KEY_STATE::RELEASED)
#define KEY_NONE(Key)		KEY_CHECK(Key, KEY_STATE::NONE)

#define DT CTimeMgr::GetInst()->GetDeltaTime()
#define DT_ENGINE CTimeMgr::GetInst()->GetDeltaTime_Engine()

#define FMOD_System CSoundMgr::GetInst()->GetFMODSystem()

#define MAX_LAYER 32

#define CLONE(Type)			virtual Type* Clone() { return new Type(*this); }
#define CLONE_DISABLE(Type) virtual Type* Clone() { return nullptr; }\
							private:\
								Type(const Type& _Other) = delete;



typedef Vector2 Vec2;
typedef Vector3 Vec3;
typedef Vector4 Vec4;