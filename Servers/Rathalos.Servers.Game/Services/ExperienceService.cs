using Microsoft.EntityFrameworkCore;
using Rathalos.Servers.Base.Services;
using Rathalos.Servers.World.Core.Databases.Records;

namespace Rathalos.Servers.World.Services
{
    [WarmupDependencies(typeof(RathalosDbService))]
    public class ExperienceService : WarmupService<ExperienceService>
    {
        private readonly Dictionary<int, (long LowerBound, long UpperBound)> _levelExperienceBounds = [];
        private int _maxLevel;

        public override async Task Initialize()
        {
            var levels = await RathalosDbService.Instance.Query<PlayerLevelUpRecord>()
                .OrderBy(l => l.Level)
                .ToListAsync();

            int cumulativeExp = 0;

            foreach (var level in levels)
            {
                int lowerBound = cumulativeExp;
                int upperBound = cumulativeExp + level.LevelUpExp - 1;

                _levelExperienceBounds[level.Level] = (lowerBound, upperBound);
                cumulativeExp += level.LevelUpExp;
            }

            _maxLevel = levels.Count > 0 ? levels.Max(l => l.Level) : 1;
        }

        /// <summary>
        /// Gets the player level for a given experience amount.
        /// </summary>
        /// <param name="experience">The total experience amount.</param>
        /// <returns>The level corresponding to the experience.</returns>
        public int GetLevelForExperience(long experience)
        {
            if (experience < 0)
                return 1;

            foreach (var kvp in _levelExperienceBounds.OrderByDescending(k => k.Key))
            {
                if (experience >= kvp.Value.LowerBound)
                    return kvp.Key;
            }

            return 1;
        }
    }
}
