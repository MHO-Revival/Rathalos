using System;
using System.Collections.Generic;
using System.Diagnostics.CodeAnalysis;

namespace Rathalos.Servers.World.Core.Game.Stats;

/// <summary>
/// A container for managing multiple attributes of a specific enum type.
/// </summary>
/// <typeparam name="T">The enum type representing attribute identifiers.</typeparam>
public sealed class AttributesFields<T>
    where T : struct, Enum
{
    private readonly Dictionary<T, IAttributeData> _attributes = new Dictionary<T, IAttributeData>();

    /// <summary>
    /// Gets the number of attributes in this container.
    /// </summary>
    public int Count => _attributes.Count;

    /// <summary>
    /// Adds or updates a string attribute in the container.
    /// </summary>
    public void SetString(StringAttributeData<T> attribute)
    {
        _attributes[attribute.Id] = attribute;
    }

    /// <summary>
    /// Gets a string attribute by its identifier.
    /// </summary>
    public StringAttributeData<T>? GetString(T id)
    {
        return _attributes.TryGetValue(id, out var attribute)
            ? attribute as StringAttributeData<T>
            : null;
    }

    /// <summary>
    /// Gets the string value of an attribute by its identifier.
    /// </summary>
    public string? GetStringValue(T id)
    {
        return GetString(id)?.Value;
    }

    /// <summary>
    /// Sets the value of an existing string attribute.
    /// </summary>
    public bool SetStringValue(T id, string? value)
    {
        var attr = GetString(id);
        if (attr != null)
        {
            attr.Value = value;
            return true;
        }
        return false;
    }
    /// <summary>
    /// Adds or updates an attribute in the container.
    /// </summary>
    /// <typeparam name="TValue">The value type of the attribute.</typeparam>
    /// <param name="attribute">The attribute to add or update.</param>
    public void Set<TValue>(AttributeData<T, TValue> attribute)
        where TValue : struct
    {
        _attributes[attribute.Id] = attribute;
    }

    /// <summary>
    /// Gets an attribute by its identifier.
    /// </summary>
    /// <typeparam name="TValue">The value type of the attribute.</typeparam>
    /// <param name="id">The attribute identifier.</param>
    /// <returns>The attribute if found; otherwise, null.</returns>
    public AttributeData<T, TValue>? Get<TValue>(T id)
        where TValue : struct
    {
        return _attributes.TryGetValue(id, out var attribute)
            ? attribute as AttributeData<T, TValue>
            : null;
    }

    public object? GetRaw(T id)
    {
        return _attributes.TryGetValue(id, out var attribute) ? attribute.ValueAsObject : null;
    }

    /// <summary>
    /// Tries to get an attribute by its identifier.
    /// </summary>
    /// <typeparam name="TValue">The value type of the attribute.</typeparam>
    /// <param name="id">The attribute identifier.</param>
    /// <param name="attribute">The attribute if found.</param>
    /// <returns>True if the attribute was found; otherwise, false.</returns>
    public bool TryGet<TValue>(T id, [NotNullWhen(true)] out AttributeData<T, TValue>? attribute)
        where TValue : struct
    {
        if (_attributes.TryGetValue(id, out var obj) && obj is AttributeData<T, TValue> typedAttr)
        {
            attribute = typedAttr;
            return true;
        }

        attribute = null;
        return false;
    }

    /// <summary>
    /// Gets the value of an attribute by its identifier.
    /// </summary>
    /// <typeparam name="TValue">The value type of the attribute.</typeparam>
    /// <param name="id">The attribute identifier.</param>
    /// <returns>The value if found; otherwise, default.</returns>
    public TValue GetValue<TValue>(T id)
        where TValue : struct
    {
        return Get<TValue>(id)?.Value ?? default;
    }

    /// <summary>
    /// Sets the value of an existing attribute.
    /// </summary>
    /// <typeparam name="TValue">The value type of the attribute.</typeparam>
    /// <param name="id">The attribute identifier.</param>
    /// <param name="value">The new value.</param>
    /// <returns>True if the attribute was found and updated; otherwise, false.</returns>
    public bool SetValue<TValue>(T id, TValue value)
        where TValue : struct
    {
        if (TryGet<TValue>(id, out var attribute))
        {
            attribute.Value = value;
            attribute.ClampValue();
            return true;
        }

        return false;
    }

    /// <summary>
    /// Checks if an attribute exists in the container.
    /// </summary>
    /// <param name="id">The attribute identifier.</param>
    /// <returns>True if the attribute exists; otherwise, false.</returns>
    public bool Contains(T id) => _attributes.ContainsKey(id);

    /// <summary>
    /// Removes an attribute from the container.
    /// </summary>
    /// <param name="id">The attribute identifier.</param>
    /// <returns>True if the attribute was removed; otherwise, false.</returns>
    public bool Remove(T id) => _attributes.Remove(id);

    /// <summary>
    /// Resets all attributes to their initial values.
    /// </summary>
    public void ResetAll()
    {
        foreach (var attr in _attributes.Values)
        {
            if (attr is IResettable resettable)
            {
                resettable.Reset();
            }
        }
    }

    /// <summary>
    /// Gets all attribute identifiers in the container.
    /// </summary>
    public IEnumerable<T> Keys => _attributes.Keys;
}

/// <summary>
/// Interface for resettable attributes.
/// </summary>
public interface IResettable
{
    /// <summary>
    /// Resets the attribute to its initial value.
    /// </summary>
    void Reset();
}
