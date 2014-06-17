#ifndef UNIFORM_H
#define UNIFORM_H

#include <string>
#include <memory>
#include <GL/glew.h>

using namespace std;

namespace ogl
{
	/** Encapslates the Uniform hierarchy so Uniforms can be put inside a container. */
	class AnyUniform
	{
	public:
		template <typename T> AnyUniform(string name, T const& value);

		~AnyUniform();

		/** Not-typed API. Use when value type is unknown. */
		string& getName();

		/** Not-typed API. Use when value type is unknown. */
		GLvoid* getRawValue();

		/** Typed API. Use when the value type is known. */
		template <typename T> T& getValue();

		/** Typed API. Use when the value type is known. */
		template <typename T> void setValue(T& value);
	private:
		/** Base for all typed uniforms. */
		class AbstractUniform
		{
		public:
			AbstractUniform(AnyUniform& anyUniform) : m_anyUniform(anyUniform) {}
			virtual ~AbstractUniform() {};
		protected:
			/** AnyUniform which wrap this instance. */
			AnyUniform& m_anyUniform;
		};

		typedef shared_ptr<AbstractUniform> AbstractUniformPtr;

		/** Represents an uniform in a shader. */
		template <typename T>
		class Uniform : public AbstractUniform
		{
		public:
			Uniform(AnyUniform& anyUniform, string name, T initialValue) :
				AbstractUniform(anyUniform), m_name(name), m_value(initialValue) {}

			~Uniform() {}

			string& getName() { return m_name; }

			/** Typed getValue. */
			T& getValue() { return m_value; }

			/** Typed setValue. */
			void setValue(T& value)
			{
				m_value = value;
				m_anyUniform.m_rawValue = (GLvoid*)&m_value;
			}
		private:
			T m_value;
			string m_name;
		};

		/** Pointer to the actual Uniform.*/
		AbstractUniformPtr m_ptr;

		/** Raw value for the not-typed API. */
		GLvoid* m_rawValue;

		/** Name for the not-typed API. */
		string m_name;
	};

	/* AnyUniform implementation. */
	template <typename T>
	AnyUniform::AnyUniform(string name, T const& value) :
		m_ptr(AbstractUniformPtr(new Uniform<T>(*this, name, value)))
	{
		m_name = dynamic_pointer_cast<Uniform<T>>(m_ptr)->getName();
		m_rawValue = (GLvoid*) &getValue<T>();
	}

	template <typename T>
	T& AnyUniform::getValue()
	{
        shared_ptr<Uniform<T>> typedUniform = dynamic_pointer_cast<Uniform<T>>(m_ptr);
		return typedUniform->getValue();
	}

	template <typename T>
	void AnyUniform::setValue(T& value)
	{
		dynamic_pointer_cast<Uniform<T>>(m_ptr)->setValue(value);
	}

	typedef shared_ptr<AnyUniform> AnyUniformPtr;
}
#endif
