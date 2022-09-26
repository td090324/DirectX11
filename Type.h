#pragma once

//추상 클래스 : 순수가상함수로만 이루어진 클래스
//순수가상함수 인터페이스
class Scene
{
public:
	virtual ~Scene() {};
	
	//순수 가상함수 virtual = 0

	//씬 초기화
	virtual void Init() = 0;
	//씬 갱신
	virtual void Update() = 0;
	//씬 출력
	virtual void Render() = 0;
};

template <typename T>
class Singleton
{
public:
    virtual ~Singleton() {};

    static T * GetInstance()
    {
        static T * Instance = new T;
        return Instance;
    };
    void DeleteSingleton()
    {
        delete GetInstance();
    };
};
