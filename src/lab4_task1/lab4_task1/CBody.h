#pragma once
//Что должно быть у класса, для безопасного удаления наследников.
class CBody
{
public:
	CBody(const std::string& shapeType);
	virtual ~CBody();

	virtual std::string GetShapeType() const;
	//Что должно быть в базовом классе, если мы не можем написать реализацию метода.
	virtual double GetDensity() const;
	virtual double GetVolume() const;
	virtual double GetMass() const;
	virtual double GetWeightInWater() const; //Не переопределять . Сделать чтобы при изменении жидкости не пришлось везде переписывать. Сделать ввод плотности жидкости в программе.

	std::string ToString() const;
	virtual void AddBody(std::shared_ptr<CBody> body); //Убрать из базоваго класса

private:
	std::string m_shapeType; //Компаунд не использует тип (криво использует)
	virtual std::string GetAdditionalParameters() const; //В приват
};