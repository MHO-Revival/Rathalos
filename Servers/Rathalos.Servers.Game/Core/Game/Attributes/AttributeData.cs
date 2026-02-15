using System;

namespace Rathalos.Servers.World.Core.Game.Stats;

public interface IAttributeData
{
    public object? ValueAsObject { get; }
}

/// <summary>
/// Represents an attribute with its metadata and value.
/// </summary>
/// <typeparam name="T">The enum type representing the attribute identifier.</typeparam>
/// <typeparam name="TValue">The value type of the attribute (int, float, bool, string, etc.).</typeparam>
public class AttributeData<T, TValue> : IResettable, IAttributeData
    where T : struct, Enum
    where TValue : struct
{
    /// <summary>
    /// Gets the attribute identifier.
    /// </summary>
    public T Id { get; }

    /// <summary>
    /// Gets the value of the attribute as an object.
    /// </summary>
    public object? ValueAsObject => Value;

    /// <summary>
    /// Gets or sets the current value of the attribute.
    /// </summary>
    public TValue Value { get; set; }

    /// <summary>
    /// Gets a value indicating whether this is a self attribute.
    /// </summary>
    public bool Self { get; }

    /// <summary>
    /// Gets a value indicating whether this attribute has bonus calculations.
    /// </summary>
    public bool Bonus { get; }

    /// <summary>
    /// Gets the initial value of the attribute.
    /// </summary>
    public TValue? InitialValue { get; }

    /// <summary>
    /// Gets the lower bound of the attribute value.
    /// </summary>
    public TValue? LowerBound { get; }

    /// <summary>
    /// Gets the upper bound of the attribute value.
    /// </summary>
    public TValue? UpperBound { get; }

    /// <summary>
    /// Initializes a new instance of the <see cref="AttributeData{T, TValue}"/> class.
    /// </summary>
    /// <param name="id">The attribute identifier.</param>
    /// <param name="value">The current value.</param>
    /// <param name="self">Whether this is a self attribute.</param>
    /// <param name="bonus">Whether this attribute has bonus calculations.</param>
    /// <param name="initialValue">The initial value.</param>
    /// <param name="lowerBound">The lower bound.</param>
    /// <param name="upperBound">The upper bound.</param>
    public AttributeData(
        T id,
        TValue value,
        bool self = false,
        bool bonus = false,
        TValue? initialValue = null,
        TValue? lowerBound = null,
        TValue? upperBound = null)
    {
        Id = id;
        Value = value;
        Self = self;
        Bonus = bonus;
        InitialValue = initialValue;
        LowerBound = lowerBound;
        UpperBound = upperBound;
    }

    /// <summary>
    /// Clamps the value to the lower and upper bounds if they are defined.
    /// </summary>
    public void ClampValue()
    {
        if (LowerBound.HasValue || UpperBound.HasValue)
        {
            var comparable = Value as IComparable<TValue>;
            if (comparable is not null)
            {
                if (LowerBound.HasValue && comparable.CompareTo(LowerBound.Value) < 0)
                {
                    Value = LowerBound.Value;
                }
                else if (UpperBound.HasValue && comparable.CompareTo(UpperBound.Value) > 0)
                {
                    Value = UpperBound.Value;
                }
            }
        }
    }

    /// <summary>
    /// Resets the value to the initial value if defined.
    /// </summary>
    public void Reset()
    {
        if (InitialValue.HasValue)
        {
            Value = InitialValue.Value;
        }
    }

    /// <summary>
    /// Gets the numeric ID of the attribute.
    /// </summary>
    public int NumericId => Convert.ToInt32(Id);
}

/// <summary>
/// Represents a string attribute with its metadata and value.
/// </summary>
public class StringAttributeData<T> : IResettable, IAttributeData
    where T : struct, Enum
{
    public T Id { get; }

    public object? ValueAsObject => Value;
    public string? Value { get; set; }
    public bool Self { get; }
    public bool Bonus { get; }
    public string? InitialValue { get; }

    public StringAttributeData(
        T id,
        string? value,
        bool self = false,
        bool bonus = false,
        string? initialValue = null)
    {
        Id = id;
        Value = value;
        Self = self;
        Bonus = bonus;
        InitialValue = initialValue;
    }

    public void Reset()
    {
        Value = InitialValue;
    }
}
