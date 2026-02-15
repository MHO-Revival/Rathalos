using System;
using Microsoft.EntityFrameworkCore.Migrations;
using Npgsql.EntityFrameworkCore.PostgreSQL.Metadata;

#nullable disable

namespace Rathalos.Core.Migrations.Migrations
{
    /// <inheritdoc />
    public partial class UpdateCharacterForAttributesAndAddPlayerLevelUps : Migration
    {
        /// <inheritdoc />
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropColumn(
                name: "Experience",
                table: "characters");

            migrationBuilder.DropColumn(
                name: "EyeBall",
                table: "characters");

            migrationBuilder.DropColumn(
                name: "EyeColor",
                table: "characters");

            migrationBuilder.DropColumn(
                name: "FaceId",
                table: "characters");

            migrationBuilder.DropColumn(
                name: "FaceTattooColor",
                table: "characters");

            migrationBuilder.DropColumn(
                name: "FaceTattooIndex",
                table: "characters");

            migrationBuilder.DropColumn(
                name: "Gender",
                table: "characters");

            migrationBuilder.DropColumn(
                name: "HRLevel",
                table: "characters");

            migrationBuilder.DropColumn(
                name: "HairColor",
                table: "characters");

            migrationBuilder.DropColumn(
                name: "HairId",
                table: "characters");

            migrationBuilder.DropColumn(
                name: "HideFashion",
                table: "characters");

            migrationBuilder.DropColumn(
                name: "HideHelm",
                table: "characters");

            migrationBuilder.DropColumn(
                name: "HideSuite",
                table: "characters");

            migrationBuilder.DropColumn(
                name: "InnerColor",
                table: "characters");

            migrationBuilder.DropColumn(
                name: "Level",
                table: "characters");

            migrationBuilder.DropColumn(
                name: "Name",
                table: "characters");

            migrationBuilder.DropColumn(
                name: "SkinColor",
                table: "characters");

            migrationBuilder.DropColumn(
                name: "SoulStoneLv",
                table: "characters");

            migrationBuilder.DropColumn(
                name: "UnderclothesId",
                table: "characters");

            migrationBuilder.RenameColumn(
                name: "FacialInfo",
                table: "characters",
                newName: "Attributes");

            migrationBuilder.CreateTable(
                name: "player_level_ups",
                columns: table => new
                {
                    Id = table.Column<long>(type: "bigint", nullable: false)
                        .Annotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn),
                    Level = table.Column<int>(type: "integer", nullable: false),
                    LevelUpExp = table.Column<int>(type: "integer", nullable: false),
                    MaxHp = table.Column<int>(type: "integer", nullable: true),
                    Strength = table.Column<int>(type: "integer", nullable: true),
                    Burst = table.Column<int>(type: "integer", nullable: true),
                    Luck = table.Column<int>(type: "integer", nullable: true),
                    Stamina = table.Column<int>(type: "integer", nullable: true),
                    HRPoints = table.Column<int>(type: "integer", nullable: false),
                    LastTimeModified = table.Column<DateTime>(type: "timestamp with time zone", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_player_level_ups", x => x.Id);
                });
            // Seed all data tables including player_level_ups
            DataSeeder.SeedPlayerLevelUpData(migrationBuilder);
        }

        /// <inheritdoc />
        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropTable(
                name: "player_level_ups");

            migrationBuilder.RenameColumn(
                name: "Attributes",
                table: "characters",
                newName: "FacialInfo");

            migrationBuilder.AddColumn<long>(
                name: "Experience",
                table: "characters",
                type: "bigint",
                nullable: false,
                defaultValue: 0L);

            migrationBuilder.AddColumn<int>(
                name: "EyeBall",
                table: "characters",
                type: "integer",
                nullable: false,
                defaultValue: 0);

            migrationBuilder.AddColumn<int>(
                name: "EyeColor",
                table: "characters",
                type: "integer",
                nullable: false,
                defaultValue: 0);

            migrationBuilder.AddColumn<int>(
                name: "FaceId",
                table: "characters",
                type: "integer",
                nullable: false,
                defaultValue: 0);

            migrationBuilder.AddColumn<int>(
                name: "FaceTattooColor",
                table: "characters",
                type: "integer",
                nullable: false,
                defaultValue: 0);

            migrationBuilder.AddColumn<int>(
                name: "FaceTattooIndex",
                table: "characters",
                type: "integer",
                nullable: false,
                defaultValue: 0);

            migrationBuilder.AddColumn<byte>(
                name: "Gender",
                table: "characters",
                type: "smallint",
                nullable: false,
                defaultValue: (byte)0);

            migrationBuilder.AddColumn<int>(
                name: "HRLevel",
                table: "characters",
                type: "integer",
                nullable: false,
                defaultValue: 0);

            migrationBuilder.AddColumn<int>(
                name: "HairColor",
                table: "characters",
                type: "integer",
                nullable: false,
                defaultValue: 0);

            migrationBuilder.AddColumn<int>(
                name: "HairId",
                table: "characters",
                type: "integer",
                nullable: false,
                defaultValue: 0);

            migrationBuilder.AddColumn<bool>(
                name: "HideFashion",
                table: "characters",
                type: "boolean",
                nullable: false,
                defaultValue: false);

            migrationBuilder.AddColumn<bool>(
                name: "HideHelm",
                table: "characters",
                type: "boolean",
                nullable: false,
                defaultValue: false);

            migrationBuilder.AddColumn<bool>(
                name: "HideSuite",
                table: "characters",
                type: "boolean",
                nullable: false,
                defaultValue: false);

            migrationBuilder.AddColumn<int>(
                name: "InnerColor",
                table: "characters",
                type: "integer",
                nullable: false,
                defaultValue: 0);

            migrationBuilder.AddColumn<int>(
                name: "Level",
                table: "characters",
                type: "integer",
                nullable: false,
                defaultValue: 0);

            migrationBuilder.AddColumn<string>(
                name: "Name",
                table: "characters",
                type: "text",
                nullable: false,
                defaultValue: "");

            migrationBuilder.AddColumn<int>(
                name: "SkinColor",
                table: "characters",
                type: "integer",
                nullable: false,
                defaultValue: 0);

            migrationBuilder.AddColumn<int>(
                name: "SoulStoneLv",
                table: "characters",
                type: "integer",
                nullable: false,
                defaultValue: 0);

            migrationBuilder.AddColumn<int>(
                name: "UnderclothesId",
                table: "characters",
                type: "integer",
                nullable: false,
                defaultValue: 0);
        }
    }
}
