#pragma once
class CBody
{
public:
	std::string GetShapeType() const;
	virtual double GetDensity() const = 0;
	virtual double GetVolume() const = 0;
	virtual double GetMass() const = 0;
	double GetWeightInWater() const;

	std::string ToString() const;
	virtual void AddBody(std::shared_ptr<CBody> body); //Убрать из базоваго класса
	//Не пашет рекурсивный compound в shapebox, если убрать.

protected:
	CBody(const std::string& shapeType);
	~CBody();

private:
	std::string m_shapeType; //Компаунд не использует тип (использует)
	virtual std::string GetAdditionalParameters() const = 0;
};
