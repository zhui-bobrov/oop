#pragma once
//��� ������ ���� � ������, ��� ����������� �������� �����������.
class CBody
{
public:
	CBody(const std::string& shapeType);
	virtual ~CBody();

	virtual std::string GetShapeType() const;
	//��� ������ ���� � ������� ������, ���� �� �� ����� �������� ���������� ������.
	virtual double GetDensity() const;
	virtual double GetVolume() const;
	virtual double GetMass() const;
	virtual double GetWeightInWater() const; //�� �������������� . ������� ����� ��� ��������� �������� �� �������� ����� ������������. ������� ���� ��������� �������� � ���������.

	std::string ToString() const;
	virtual void AddBody(std::shared_ptr<CBody> body); //������ �� �������� ������

private:
	std::string m_shapeType; //�������� �� ���������� ��� (����� ����������)
	virtual std::string GetAdditionalParameters() const; //� ������
};